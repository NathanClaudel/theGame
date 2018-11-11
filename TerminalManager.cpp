#include <sstream>

#include "FileElementFactory.h"
#include "TerminalManager.h"
#include "Directory.h"
#include "RootDirectory.h"

TerminalManager::TerminalManager(Printer &printer) :
    m_printer(printer)
{
    m_currentDirectory = new RootDirectory("~/game");
}

TerminalManager::TerminalManager(Printer &printer, const std::string &fileName) :
    m_printer(printer)
{
    m_currentDirectory = FileElementFactory::readObject(fileName);
}

TerminalManager::~TerminalManager()
{
    delete m_currentDirectory;
}

std::string TerminalManager::information()
{
    return "\033[1;32myou@game\033[0m:" + m_currentDirectory->path() + "$ ";
}

void TerminalManager::executeCommand(const std::string &command)
{
    std::stringstream ss(command);
    std::string token;

    std::getline(ss, token, ' ');
    if(token == "cd")
    {
        std::getline(ss, token, ' ');
        m_currentDirectory = m_currentDirectory->cdElement(m_printer, token);
    }
    else
    {
        m_currentDirectory->executeCommand(m_printer, command);
    }
}
