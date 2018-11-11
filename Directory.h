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

    virtual DirectoryPtr cdElement(Printer &out, const std::string name);
    virtual void executeCommand(Printer &out, const std::string &command);

    virtual void entryAction(Printer &out);
    virtual void outAction(Printer &out);

    virtual void rmAction(Printer &out) override;
    virtual int isRemovable(Printer &out, const std::string &arg) override;

    // Directory specific actions
    virtual void lsElements(Printer &out);
    virtual void rmElement(Printer &out, const std::string &name, const std::string args);
    virtual void mkdirAction(Printer &out, const std::string &name);
    virtual void pwdAction(Printer &out);

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
