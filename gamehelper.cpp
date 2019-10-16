#include "gamehelper.h"
#include <iostream>
#include <stdio.h>
#include <QDebug>
#include <QProcess>
#include "qglobal.h"
#include "game_demo/gamedemo.h"

GameHelper::GameHelper()
{

}

Game *GameHelper::createInstance(selectedGame gametype)
{

    switch(gametype) {

    case(eGAME_DEMO):
        return new GameDemo();
    default:
        return nullptr;
    }


}

void GameHelper::print(const gamedata *data)
{

#ifdef Q_OS_LINUX
    QProcess::execute("clear");
#elif defined(Q_OS_WIN)
    QProcess::execute("CLS");
#endif

    printf("Version : %d \n", data->version);
    printf("Game    : %d \n", data->gameType);
    printf("--- \n");
    printf("Gear %d of %d \n", data->gear, data->maxGear);
    printf("RPM %d of %d \n", data->rpm, data->maxRpm);
}
