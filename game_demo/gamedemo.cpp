#include "game_demo/gamedemo.h"

GameDemo::GameDemo()
{

}

bool GameDemo::writeDataTo(gamedata *data)
{
    data->gameType = eGAME_DEMO;




    data->maxGear = 6;
    data->gear %= data->maxGear;
    data->gear++;

    data->maxRpm = 10000;
    data->rpm %= data->maxRpm;
    data->rpm += 500;

    data->racePosition %= 20;
    data->racePosition++;

    return true;
}

bool GameDemo::isRunning()
{
    return true;
}
