#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QMap>
#include <QObject>
#include <QString>

#define CFG_SHAREDMEMORY_ENABLE "sharedmemory_enable"
#define CFG_SHAREDMEMORY_KEY "sharedmemory_key"
#define CFG_SERIAL_PORT "serial_port"
#define CFG_SERIAL_BAUDRATE "serial_baudrate"
#define CFG_REFRESH_MS "refresh_ms"

class Configuration {

      public:
	static void print();
	static bool load(QString filename);
	static bool hasValue(QString key);
	static int valueInteger(QString key, bool *ok = nullptr);
	static QString valueString(QString key, bool *ok = nullptr);

      private:
	Configuration();
	static void parseLine(QString line);

      private:
	static QString m_filename;
	static QMap<QString, QString> m_configMap;
};

#endif // CONFIGURATION_H
