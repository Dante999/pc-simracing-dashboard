#include "gamehelper.h"
#include "game_demo/gamedemo.h"
#include "qglobal.h"
#include <QDebug>
#include <QProcess>
#include <iostream>
#include <stdio.h>

GameHelper::GameHelper() {}

Game *GameHelper::createInstance(selectedGame gametype) {

	switch (gametype) {

	case (eGAME_DEMO):
		return new GameDemo();
	default:
		return nullptr;
	}
}

void GameHelper::print(const gamedata *data) {

#ifdef Q_OS_LINUX
	QProcess::execute("clear");
#elif defined(Q_OS_WIN)
	QProcess::execute("CLS");
#endif

	printf("Version : %d \n", data->version);
	printf("Game    : %d \n", data->game);
	printf("--- \n");
	printf("Gear %d of %d \n", data->gear, data->gear_max);
	printf("RPM %d of %d \n", data->rpm, data->rpm_max);
	printf("--- \n");
	printf("| %3s | %3s | %3s | %3s |\n", "TC", "TC2", "ABS", "MAP");
	printf("| %3i | %3i | %3i | %3i |\n", data->ecu_tc, data->ecu_tc2,
	       data->ecu_abs, data->ecu_enginemap);

	printf("--- \n");
	printf("Indicator %i <--> %i  \n",
	       isSet(data->car_flags1, eCAR1_INDICATOR_LEFT),
	       isSet(data->car_flags1, eCAR1_INDICATOR_RIGHT));
	printf("Headlight %i\n", isSet(data->car_flags1, eCAR1_HEAD_LIGHT));
	printf("Rainlight %i\n", isSet(data->car_flags1, eCAR1_RAIN_LIGHT));
}

uint8_t GameHelper::isSet(uint8_t byte, uint8_t mask) {
	return (byte & mask) ? 1 : 0;
}
