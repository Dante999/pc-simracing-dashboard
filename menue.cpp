#include "menue.h"

#include <iostream>

Menue::Menue()
{

}

void Menue::printWelcome()
{
    std::cout << "###############################################" << std::endl;
    std::cout << "# Simracing Dashboard                         #" << std::endl;
    std::cout << "###############################################" << std::endl;
    std::cout << std::endl;
}

selectedGame Menue::askForGame()
{
    char c;

    std::cout << "Please enter the number for your game" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "[0] Project Cars 1" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Enter your game number: ";
    std::cin >> c;

    switch (c) {

    case '0':
        return eGAME_PCARS;
        break;
    default:
        return eGAME_UNKNOWN;
    }
}
