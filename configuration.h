#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include <QMap>
#include <QString>

class Configuration
{

public:
    Configuration(QString filename);
    bool initialize();
    bool containsValue(QString key);
    int getValueAsInt(QString key, bool *ok = nullptr);
    QString getValueAsString(QString key, bool *ok);


private:
    void parseLine(QString line);

private:
    QString m_filename;
    QMap<QString, QString> m_configMap;

};

#endif // CONFIGURATION_H
