#include "game_demo/gamedemo.h"

GameDemo::GameDemo()
{

}

bool GameDemo::writeDataTo(gameDataStruct *gameData)
{
    gameData->gameType = eGAME_DEMO;

    return true;
}

bool GameDemo::isRunning()
{
    return true;
}
