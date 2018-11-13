#include <unistd.h>

#include "ProgramLauncher.h"

ProgramLauncher::ProgramLauncher(DirectoryPtr parent,
                                 const std::string &name,
                                 const std::string &programName,
                                 unsigned int nbLaunches) :
    FileElement(parent, name),
    m_programName(programName),
    m_delay(0),
    m_nbLaunches(nbLaunches)
{

}

ProgramLauncher::ProgramLauncher(DirectoryPtr parent,
                                 const std::string &name,
                                 const std::string &programName,
                                 unsigned int nbLaunches,
                                 unsigned int delay) :
    ProgramLauncher(parent, name, programName, nbLaunches)
{
    m_delay = delay;
}

void ProgramLauncher::executeAction(Printer &)
{
    for(unsigned int i = 0; i < m_nbLaunches; i++)
    {
        int unused = system((m_programName + " &").c_str());
        (void)unused;
        usleep(m_delay);
    }
}

void ProgramLauncher::writeObject(std::ofstream &out)
{
    FileElement::writeObject(out);
    out << m_programName << std::endl;
    out << std::to_string(m_nbLaunches) << std::endl;
}

FileElementPtr ProgramLauncher::readObject(std::ifstream &in, DirectoryPtr parent)
{
    std::string name;
    std::getline(in, name);

    std::string programName;
    std::getline(in, programName);

    std::string nbLaunchesStr;
    std::getline(in, nbLaunchesStr);

    return new ProgramLauncher(parent, name, programName, std::stoi(nbLaunchesStr));
}

std::string ProgramLauncher::_className()
{
    return "ProgramLauncher";
}
