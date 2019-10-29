#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <stdint.h>

#define VERSION 1

enum selectedGame {
	eGAME_UNKNOWN = 0,
	eGAME_DEMO,
	eGAME_PCARS
	// ------------
};

// Tyres
enum tyre {
	eTYRE_FRONT_LEFT = 0,
	eTYRE_FRONT_RIGHT,
	eTYRE_REAR_LEFT,
	eTYRE_REAR_RIGHT,
	//--------------
	eTYRE_MAX
};

// (Type#9) Car Flags (to be used with 'mCarFlags')
enum car_flag1 {
	eCAR1_HEAD_LIGHT      = (1 << 0),
	eCAR1_RAIN_LIGHT      = (1 << 1),
	eCAR1_INDICATOR_LEFT  = (1 << 2),
	eCAR1_INDICATOR_RIGHT = (1 << 3),
	eCAR1_ENGINE_ACTIVE   = (1 << 4),
	eCAR1_ENGINE_WARNING  = (1 << 5),
};

enum car_flag2 {
	eCAR2_PIT_LIMITER   = (1 << 0),
	eCAR2_TC_TRIGGERED  = (1 << 1),
	eCAR2_ABS_TRIGGERED = (1 << 2),
	eCAR2_HANDBRAKE     = (1 << 3),
};

struct gamedata {
	uint8_t version = VERSION;
	uint8_t game;

	int8_t gear;
	int8_t gear_max;
	uint16_t rpm;
	uint16_t rpm_max;
	uint16_t speed;
	uint8_t fuel_level;
	uint8_t fuel_capacity;

	uint8_t ecu_brakebias;
	uint8_t ecu_tc;
	uint8_t ecu_tc2;
	uint8_t ecu_abs;
	uint8_t ecu_enginemap;

	uint16_t tmp_tyre[eTYRE_MAX];
	uint16_t tmp_brake[eTYRE_MAX];
	uint16_t tmp_oil;
	uint16_t tmp_water;

	uint8_t dmg_aero;
	uint8_t dmg_engine;
	uint8_t dmg_brake[eTYRE_MAX];
	uint8_t dmg_suspension[eTYRE_MAX];
	uint8_t dmg_tyre[eTYRE_MAX];

	uint8_t car_flags1;
	uint8_t car_flags2;

	uint8_t raceposition;

	float time_bestlap;
	float time_lastlap;
	float time_splitahead;
	float time_splitbehind;
};

#endif // GAMEDATA_H
