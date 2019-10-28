#ifndef MENUE_H
#define MENUE_H

#include "gamedata.h"

class Menue {
      public:
	Menue();
	static void printWelcome();
	static enum selectedGame askForGame();
};

#endif // MENUE_H
