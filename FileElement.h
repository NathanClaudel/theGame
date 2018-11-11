#ifndef FILEELEMENT_H
#define FILEELEMENT_H

#include <string>
#include <iostream>

#include "PtrDefinition.h"

class FileElement
{
public:
    FileElement(DirectoryPtr parent, const std::string name);
    virtual ~FileElement();

    virtual const std::string &name() const {return m_name;}
    virtual const std::string &path();
    virtual DirectoryPtr parent() {return m_parent;}

    virtual void lsAction(std::ostream &out);
    virtual void rmAction(std::ostream &);

    virtual int isRemovable(std::ostream &out, const std::string &arg);

protected:
    virtual void _debug(const std::string &message);
    virtual std::string _className();

private:
    const std::string m_name;
    DirectoryPtr m_parent;
};

#endif // FILEELEMENT_H
