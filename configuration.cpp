#include "configuration.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

/*
 * the filepath to the configuration file
 */
QString Configuration::m_filename = "";

/*
 * a map with all loaded key-value pairs from the configuration file
 */
QMap<QString, QString> Configuration::m_configMap;

/*******************************************************************************
 * default constructor
 *
 * @param   none
 *
 * @return  none
 ******************************************************************************/
Configuration::Configuration() {}

/*******************************************************************************
 * prints all loaded configuration values
 *
 * @param   none
 *
 * @return  none
 ******************************************************************************/
void Configuration::print()
{
	QMapIterator<QString, QString> iter(m_configMap);

	qDebug() << "+----------------------+";
	qDebug() << "| configuration values |";
	qDebug() << "+----------------------+";

	while (iter.hasNext()) {
		iter.next();
		qDebug() << iter.key() << " : " << iter.value();
	}
}

/*******************************************************************************
 * loads all configuration values from the given file
 *
 * @param   filename   the filepath to the configuration file
 *
 * @return  true if loading the values succeed, otherwise false
 ******************************************************************************/
bool Configuration::load(QString filename)
{
	m_filename = filename;

	QFile configurationFile(m_filename);

	if (!configurationFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qCritical() << "Unable to open configfile: " << m_filename;
		return false;
	}

	QTextStream configStream(&configurationFile);

	while (!configStream.atEnd()) {
		QString line = configStream.readLine();

		if (!line.isEmpty() && !line.startsWith('#'))
			parseLine(line);
	}

	configurationFile.close();

	return true;
}

/*******************************************************************************
 * checks if a configuration value with the given key exists
 *
 * @param   key   the name of the configuration value
 *
 * @return  true if the value exists, otherwise false
 ******************************************************************************/
bool Configuration::hasValue(QString key) { return m_configMap.contains(key); }

/*******************************************************************************
 * returns the configuration value as an integer
 *
 * @param   key   the key of the configuration value
 * @param   *ok   will be set to true if everything is ok, otherwise false
 *
 * @return  the value of the given key, could also be 0 if anything went wrong
 ******************************************************************************/
int Configuration::valueInteger(QString key, bool *ok)
{
	bool sucess = false;
	int  value  = 0;

	if (m_configMap.contains(key)) {
		value = m_configMap.value(key).toInt(&sucess);
	} else {
		qCritical() << "No value for parameter" << key << "found!";
	}

	if (ok != nullptr)
		*ok = sucess;

	return value;
}

/*******************************************************************************
 * returns the configuration value as a string
 *
 * @param   key   the key of the configuration value
 * @param   *ok   will be set to true if everything is ok, otherwise false
 *
 * @return  the value of the given key, could also be empty if anything went
 *          wrong
 ******************************************************************************/
QString Configuration::valueString(QString key, bool *ok)
{
	bool    sucess = false;
	QString value  = "";

	if (m_configMap.contains(key)) {
		sucess = true;
		value  = m_configMap.value(key);
	} else {
		qCritical() << "No value for parameter" << key << "found!";
	}

	if (ok != nullptr)
		*ok = sucess;

	return value;
}

/*******************************************************************************
 * parses a single line of the configuration file and saves it to the internal
 * map
 *
 * @param   line   a  single line of the configuration file
 *
 * @return  none
 ******************************************************************************/
void Configuration::parseLine(QString line)
{
	int index_left  = line.indexOf('=');
	int index_right = line.length() - (index_left + 1);

	QString key   = line.left(index_left);
	QString value = line.right(index_right);

	key   = key.trimmed();
	value = value.trimmed();

	m_configMap.insert(key, value);
}
