#ifndef GAMEHELPER_H
#define GAMEHELPER_H

#include "game.h"
#include "gamedata.h"
#include <stdint.h>

class GameHelper {
      public:
	GameHelper();

	static Game *createInstance(enum selectedGame gametype);
	static void print(const struct gamedata *data);

      private:
	static uint8_t isSet(uint8_t byte, uint8_t mask);
};

#endif // GAMEHELPER_H
