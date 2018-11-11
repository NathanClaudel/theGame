#ifdef POLITE

#include <iostream>
#include <string>

#include "Politeness.h"
#include "TerminalManager.h"

int main(int argc, char* argv[])
{
    Politeness::politeTest(argc, argv, std::cout);
    std::cout << "Game 100% running" << std::endl;

    TerminalManager manager;
    std::string command;

    while(1)
    {
        std::cout << manager.information();
        getline(std::cin, command);
        manager.processCommand(std::string(command));
    }
}

#endif
