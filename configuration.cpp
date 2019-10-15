#include "configuration.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

/*
 * initialize static class members
 */
QString Configuration::m_filename = "";
QMap<QString, QString> Configuration::m_configMap;




Configuration::Configuration()
{
    // nothing to do
}




void Configuration::printConfiguration()
{
    QMapIterator<QString, QString> iter(m_configMap);

    qDebug() << "------------------------";
    qDebug() << "| configuration values |";
    qDebug() << "------------------------";

    while(iter.hasNext())
    {
        iter.next();
        qDebug() << iter.key() << " : " << iter.value();
    }
}

bool Configuration::load(QString filename)
{
    m_filename = filename;

    QFile configurationFile(m_filename);

    if( !configurationFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        qCritical() << "Unable to open configfile: " << m_filename;
        return false;
    }

    QTextStream configStream(&configurationFile);

    while( !configStream.atEnd() )
    {
        QString line = configStream.readLine();

        if( !line.isEmpty() && !line.startsWith('#') )
        {
            parseLine(line);
        }

    }

    configurationFile.close();

    return true;
}


bool Configuration::containsValue(QString key)
{
    return m_configMap.contains(key);
}


int Configuration::getValueAsInt(QString key, bool *ok)
{
    if( m_configMap.contains(key) )
    {
        return m_configMap.value(key).toInt(ok);
    }
    else
    {
        qCritical() << "No value for parameter" << key << "found!";
        *ok = false;
        return 0;
    }
}


QString Configuration::getValueAsString(QString key, bool *ok)
{
    if( m_configMap.contains(key) )
    {
        *ok = true;
        return m_configMap.value(key);
    }
    else
    {
        *ok = false;
        return "";
    }
}


void Configuration::parseLine(QString line)
{
    int index_left  = line.indexOf('=');
    int index_right = line.length()-(index_left+1);

    QString key   = line.left(index_left);
    QString value = line.right(index_right);

    key   = key.trimmed();
    value = value.trimmed();

    m_configMap.insert(key, value);

    //qDebug() << "configline:" << key << "=" << value;
}

