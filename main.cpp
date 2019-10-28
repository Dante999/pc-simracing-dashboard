#include "configuration.h"
#include "menue.h"
#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <iostream>

#include "gamehelper.h"

// static QString getConfigfile(int argc, char *argv[])
//{
//    for( int i=1; i< argc; i )
//    {

//    }
//}

static void start(enum selectedGame gameselection) {

	Game *gameInstance = GameHelper::createInstance(gameselection);

	struct gamedata data;

	memset(&data, 0, sizeof(data));

	while (true) {

		if (gameInstance->isRunning()) {
			gameInstance->writeDataTo(&data);
			GameHelper::print(&data);
			QThread::msleep(500);
		}
	}
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
