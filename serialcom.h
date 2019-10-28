#ifndef SERIALCOM_H
#define SERIALCOM_H

#include "stdint.h"
#include <QtSerialPort/QSerialPort>

#include "protocol.h"

class SerialCom : public QSerialPort {
	Q_OBJECT

      private:
	enum parseState {
		WAITFOR_SYNC,
		WAITFOR_CMD,
		WAITFOR_LENGTH,
		WAITFOR_DATA
	};

	parseState m_state;
	serialPackage m_received;

	void parseSingleByte(char byte);

      public:
	SerialCom(QString portName, qint32 baudRate = QSerialPort::Baud19200);
	void writeData(serialCommands cmd, uint8_t dataLength,
		       const char *data);

      signals:
	void parsingComplete(serialPackage dataPackage);

      private slots:
	void parseAllReceivedBytes();
};

#endif // SERIALCOM_H
