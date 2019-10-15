#ifndef GAMEDEMO_H
#define GAMEDEMO_H

#include "../game.h"

class GameDemo : public Game
{
public:
    GameDemo();
    bool writeDataTo(gameDataStruct *gameData);
    bool isRunning();
};

#endif // GAMEDEMO_H
