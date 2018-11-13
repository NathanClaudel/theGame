#ifndef FILEELEMENT_H
#define FILEELEMENT_H

#include <string>
#include <fstream>

#include "Printer.h"
#include "PtrDefinition.h"

class FileElement
{
public:
    FileElement(DirectoryPtr parent, const std::string name);
    virtual ~FileElement();

    virtual const std::string &name() const {return m_name;}
    virtual const std::string &path();
    virtual DirectoryPtr parent() {return m_parent;}

    virtual void lsAction(Printer &out);
    virtual void rmAction(Printer &);
    virtual void catAction(Printer &out);
    virtual void executeAction(Printer &out);

    virtual int isRemovable(Printer &out, const std::string &arg);

    virtual void writeObject(std::ofstream &out);
    static FileElementPtr readObject(std::ifstream &in, DirectoryPtr parent);

protected:
    virtual void _debug(const std::string &message);
    virtual std::string _className();

private:
    const std::string m_name;
    DirectoryPtr m_parent;
};

#endif // FILEELEMENT_H
