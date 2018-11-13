#ifndef PROGRAMLAUNCHER_H
#define PROGRAMLAUNCHER_H

#include "PtrDefinition.h"
#include "FileElement.h"

class ProgramLauncher : public FileElement
{
public:
    ProgramLauncher(DirectoryPtr parent,
                    const std::string &name,
                    const std::string &programName,
                    unsigned int nbLaunches);

    ProgramLauncher(DirectoryPtr parent,
                    const std::string &name,
                    const std::string &programName,
                    unsigned int nbLaunches,
                    unsigned int delay);

    virtual void executeAction(Printer &out) override;

    virtual void writeObject(std::ofstream &out) override;
    static FileElementPtr readObject(std::ifstream &in, DirectoryPtr parent);

protected:
    virtual std::string _className() override;

private:
    std::string m_programName;
    unsigned int m_delay;
    unsigned int m_nbLaunches;
};

#endif // PROGRAMLAUNCHER_H
