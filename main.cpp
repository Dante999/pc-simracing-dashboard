#include <QCoreApplication>
#include "configuration.h"
#include <iostream>
#include <QDebug>






int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString configfilename = "simracing-dashboard.conf";

    if( argc == 2 )
    {
        configfilename = QString(argv[1]);
        qInfo() << "loading configuration from file" << configfilename;
    }


    Configuration config(configfilename);

    config.initialize();

    return a.exec();
}
