#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include <QMap>
#include <QString>

class Configuration
{

public:
    static void printConfiguration();
    static bool load(QString filename);
    static bool containsValue(QString key);
    static int getValueAsInt(QString key, bool *ok = nullptr);
    static QString getValueAsString(QString key, bool *ok);


private:
    Configuration();
    static void parseLine(QString line);

private:
    static QString m_filename;
    static QMap<QString, QString> m_configMap;

};

#endif // CONFIGURATION_H
