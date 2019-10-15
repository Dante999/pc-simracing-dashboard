#include "game_demo/gamedemo.h"

GameDemo::GameDemo()
{

}

bool GameDemo::writeDataTo(gamedata *data)
{
    data->gameType = eGAME_DEMO;

    return true;
}

bool GameDemo::isRunning()
{
    return true;
}
