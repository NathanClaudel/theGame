
#include <iostream>
#include <string>
#include <vector>
#include <signal.h>

#include "Politeness.h"
#include "TerminalManager.h"
#include "Printer.h"

void interruptHandler(int);

Printer &printer = *new Printer(std::cout);

#ifdef POLITE
int main(int argc, char* argv[])
{
    signal(SIGINT, interruptHandler);

    Politeness::politeTest(argc, argv, printer);
    printer.println(Printer::QUICK, "\nInitializing game...");
    printer.println(Printer::QUICK, "Loading world...");
    printer.print(Printer::MEDIUM, "[****************************]");
    printer.println(Printer::QUICK, Printer::GREEN, " 100% SUCCESSFUL");
    printer.println(Printer::QUICK, "Loading assets...");
    printer.print(Printer::MEDIUM, "[****************************]");
    printer.println(Printer::QUICK, Printer::GREEN, " 100% SUCCESSFUL");
    printer.println(Printer::QUICK, "Loading graphics UI...");
    printer.print(Printer::MEDIUM, "[********");
    printer.print(Printer::SLOW, "*******");
    printer.print(Printer::VERY_SLOW, "***");
    printer.print("  ");
    printer.println(Printer::SLOW, Printer::RED, "FAILURE");
    printer.println(Printer::QUICK, Printer::RED, "Please open the UI manually "
                                          "using the command line interface.\n");
    TerminalManager manager(printer, "file");
    std::string command;

    while(1)
    {
        printer.print(manager.information());
        getline(std::cin, command);
        manager.executeCommand(std::string(command));
    }
}

#else

int main()
{
    Politeness::bePolite(printer);
}
#endif

void interruptHandler(int)
{
    std::vector<std::string> sadSentences =
    {"Leaving already ?",
     "Come on, stay a little bit...",
     "Where are you going ?",
     "* sob *",
     "I just started having fun...",
     "So disappointing."};
    srand(static_cast<unsigned int>(clock()));
    printer.println(Printer::MEDIUM,
                "\n" + sadSentences.at(static_cast<unsigned int>(rand()) % sadSentences.size()));
}
