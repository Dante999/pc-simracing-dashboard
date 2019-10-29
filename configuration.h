#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QMap>
#include <QObject>
#include <QString>

#define CFG_SHAREDMEMORY_ENABLE "sharedmemory_enable"
#define CFG_SHAREDMEMORY_KEY "sharedmemory_key"

class Configuration {

      public:
	static void printConfiguration();
	static bool load(QString filename);
	static bool containsValue(QString key);
	static int integerValue(QString key, bool *ok = nullptr);
	static QString stringValue(QString key, bool *ok = nullptr);

      private:
	Configuration();
	static void parseLine(QString line);

      private:
	static QString m_filename;
	static QMap<QString, QString> m_configMap;
};

#endif // CONFIGURATION_H
