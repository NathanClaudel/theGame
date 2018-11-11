#ifndef TERMINALMANAGER_H
#define TERMINALMANAGER_H

#include "PtrDefinition.h"

class TerminalManager
{
public:
    TerminalManager();
    virtual ~TerminalManager();

    std::string information();

    void processCommand(const std::string &command);

private:
    std::ostream &m_out;
    DirectoryPtr m_currentDirectory;
};

#endif // TERMINALMANAGER_H
