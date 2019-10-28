#ifndef GAME_H
#define GAME_H

#include "gamedata.h"

class Game {
      public:
	Game();
	virtual ~Game();
	virtual bool writeDataTo(struct gamedata *data) = 0;
	virtual bool isRunning()			= 0;
};

#endif // GAME_H
