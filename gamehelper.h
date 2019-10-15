#ifndef GAMEHELPER_H
#define GAMEHELPER_H

#include "game.h"
#include "gamedata.h"

class GameHelper
{
public:
    GameHelper();

    static Game *createInstance(enum selectedGame gametype);
    static void print(const struct gamedata *data);

};

#endif // GAMEHELPER_H
