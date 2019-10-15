#include "game_demo/gamedemo.h"

GameDemo::GameDemo()
{

}

bool GameDemo::writeDataTo(gamedata *data)
{
    data->gameType = eGAME_DEMO;




    data->maxGear = 6;


    data->gear = data->gear % data->maxGear;
    data->gear++;

    return true;
}

bool GameDemo::isRunning()
{
    return true;
}
