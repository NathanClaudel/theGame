#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <map>
#include <iostream>

#include "FileElement.h"

class Directory: public FileElement
{
public:
    Directory(DirectoryPtr parent, const std::string name);
    virtual ~Directory() override;

    virtual void entryAction(std::ostream &out);
    virtual void outAction(std::ostream &out);

    virtual void rmAction(std::ostream &out) override;
    virtual int isRemovable(std::ostream &out, const std::string &arg) override;

    // Directory specific actions
    virtual void lsElements(std::ostream &out);
    virtual void rmElement(std::ostream &out, const std::string &name, const std::string args);
    virtual DirectoryPtr cdElement(std::ostream &out, const std::string name);
    virtual void mkdirAction(std::ostream &out, const std::string &name);

protected:
    void _remove(const std::string name);
    FileElementPtr _find(const std::string name);
    DirectoryPtr _findDirectory(const std::string name);

    virtual std::string _className() override;

private:
    std::map<std::string, DirectoryPtr> m_directories;
    std::map<std::string, FileElementPtr> m_elements;
    std::string m_entryMessage;
    std::string m_outMessage;
};

#endif // DIRECTORY_H
