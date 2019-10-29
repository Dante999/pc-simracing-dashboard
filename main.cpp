#include "configuration.h"
#include "gamehelper.h"
#include "menue.h"
#include <QCoreApplication>
#include <QDebug>
#include <QSharedMemory>
#include <QThread>
#include <iostream>

// static QString getConfigfile(int argc, char *argv[])
//{
//    for( int i=1; i< argc; i )
//    {

//    }
//}

static int shdmemory_init(QSharedMemory *sharedMemory, QString memoryKey) {

	size_t memorySize = sizeof(struct gamedata);

	sharedMemory->setNativeKey(memoryKey);

	if (!sharedMemory->attach() &&
	    sharedMemory->error() == QSharedMemory::NotFound) {
	}

	if (!sharedMemory->create(memorySize)) {

		int error = sharedMemory->error();

		if (error == QSharedMemory::AlreadyExists &&
		    !sharedMemory->attach()) {
			qWarning() << "Unable to attach to existing memory: "
				   << sharedMemory->errorString();
			return -1;
		}

		return 0;
	}

	return 0;
}

static void shdmemory_update(QSharedMemory *sharedMemory,
			     struct gamedata *data) {

	void *shd_data = sharedMemory->data();

	memcpy(shd_data, (void *)data, sizeof(struct gamedata));
}

static void start(enum selectedGame gameselection) {

	QSharedMemory sharedMemory;
	Game *gameInstance = nullptr;

	struct gamedata data;
	memset(&data, 0, sizeof(data));

	int shdEnabled = Configuration::integerValue(CFG_SHAREDMEMORY_ENABLE);

	if (shdEnabled) {
		QString key = Configuration::stringValue(CFG_SHAREDMEMORY_KEY);

		if (shdmemory_init(&sharedMemory, key) != 0)
			goto end_cleanup;
	}

	gameInstance = GameHelper::createInstance(gameselection);

	while (true) {

		if (gameInstance->isRunning()) {
			gameInstance->writeDataTo(&data);
			GameHelper::print(&data);

			if (shdEnabled)
				shdmemory_update(&sharedMemory, &data);
			QThread::msleep(500);
		}
	}

end_cleanup:
	sharedMemory.detach();
	if (gameInstance != nullptr)
		delete gameInstance;
}

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	Menue::printWelcome();
	enum selectedGame selected = Menue::askForGame();

	QString configfilename = "simracing-dashboard.conf";

	if (argc == 2) {
		configfilename = QString(argv[1]);
		qInfo() << "loading configuration from file" << configfilename;
	}

	Configuration::load(configfilename);
	Configuration::printConfiguration();

	start(selected);

	return a.exec();
}
