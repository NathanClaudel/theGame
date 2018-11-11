#ifndef TERMINALMANAGER_H
#define TERMINALMANAGER_H

#include "Printer.h"
#include "PtrDefinition.h"

class TerminalManager
{
public:
    TerminalManager(Printer &printer);
    TerminalManager(Printer &printer, const std::string &fileName);
    virtual ~TerminalManager();

    std::string information();

    void executeCommand(const std::string &command);

private:
    DirectoryPtr m_currentDirectory;
    Printer &m_printer;
};

#endif // TERMINALMANAGER_H
