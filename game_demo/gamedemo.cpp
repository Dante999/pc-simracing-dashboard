#include "game_demo/gamedemo.h"

GameDemo::GameDemo() {}

bool GameDemo::writeDataTo(gamedata *data) {
	data->game = eGAME_DEMO;

	data->gear_max = 6;
	data->gear %= data->gear_max;
	data->gear++;

	data->rpm_max = 10000;
	data->rpm %= data->rpm_max;
	data->rpm += 500;

	data->raceposition %= 20;
	data->raceposition++;

	data->ecu_brakebias %= 100;
	data->ecu_brakebias++;
	data->ecu_abs %= 15;
	data->ecu_abs++;
	data->ecu_tc %= 15;
	data->ecu_tc++;
	data->ecu_tc2 %= 15;
	data->ecu_tc2++;
	data->ecu_enginemap %= 15;
	data->ecu_enginemap++;

	data->car_flags1 ^= eCAR1_INDICATOR_LEFT;

	if (data->car_flags1 & eCAR1_INDICATOR_LEFT) {
		data->car_flags1 &= ~eCAR1_INDICATOR_RIGHT;
	} else {
		data->car_flags1 |= eCAR1_INDICATOR_RIGHT;
	}

	return true;
}

bool GameDemo::isRunning() { return true; }
