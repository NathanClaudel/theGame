#include <sstream>

#include "TerminalManager.h"
#include "Directory.h"
#include "RootDirectory.h"

TerminalManager::TerminalManager() :
    m_out(std::cout)
{
    m_currentDirectory = new RootDirectory();
}

TerminalManager::~TerminalManager()
{
    delete m_currentDirectory;
}

std::string TerminalManager::information()
{
    return "\033[1;32myou@game\033[0m:" + m_currentDirectory->path() + "$";
}

void TerminalManager::processCommand(const std::string &command)
{
    std::stringstream ss(command);
    std::string token;

    std::getline(ss, token, ' ');
    if(token == "ls")
    {
        m_currentDirectory->lsElements(m_out);
    }
    else if(token == "mkdir")
    {
        while(std::getline(ss, token, ' '))
            m_currentDirectory->mkdirAction(m_out, token);
    }
    else if(token == "rm")
    {
        while(std::getline(ss, token, ' '))
            m_currentDirectory->rmElement(m_out, token, "-r");
    }
    else if(token == "cd")
    {
        std::getline(ss, token, ' ');
        m_currentDirectory = m_currentDirectory->cdElement(m_out, token);
    }
    else
    {
        m_out << "Unknown command " + token;
    }
}
