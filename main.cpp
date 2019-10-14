#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include "configuration.h"
#include "menue.h"




//static QString getConfigfile(int argc, char *argv[])
//{
//    for( int i=1; i< argc; i )
//    {

//    }
//}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Menue::printWelcome();
    enum selectedGame selected = Menue::askForGame();


    QString configfilename = "simracing-dashboard.conf";

    if( argc == 2 )
    {
        configfilename = QString(argv[1]);
        qInfo() << "loading configuration from file" << configfilename;
    }


    Configuration::load(configfilename);
    Configuration::printConfiguration();
    //Configuration config(configfilename);

    //config.initialize();

    return a.exec();
}
