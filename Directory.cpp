#include <sstream>

#include "Directory.h"

Directory::Directory(DirectoryPtr parent, const std::string name) :
    FileElement (parent, name),
    m_directories(),
    m_elements()
{
    _debug("constructor");
}

Directory::~Directory()
{
    for(auto it = m_elements.begin(); it != m_elements.end(); it ++)
    {
        delete it->second;
    }
}

void Directory::entryAction(Printer &)
{

}

void Directory::outAction(Printer &)
{

}

void Directory::lsElements(Printer &out)
{
    _debug("lsAction");

    for(auto it = m_elements.begin(); it != m_elements.end(); it ++)
    {
        it->second->lsAction(out);
    }
}

void Directory::rmElement(Printer &out, const std::string &name, const std::string args)
{
    FileElementPtr element = _find(name);
    if(element == nullptr)
    {
        out.println("rm: cannot remove '" + name + "': No such file or directory");
    }
    else
    {
        if(element->isRemovable(out, args))
        {
            _remove(element->name());
        }
    }
}

DirectoryPtr Directory::cdElement(Printer &out, const std::string name)
{
    if(name == "..")
    {
        outAction(out);
        return parent() == nullptr ? this : parent();
    }
    DirectoryPtr directory = _findDirectory(name);
    if(directory == nullptr)
    {
        out.println("cd: " + name + ": No such file or directory");
        return this;
    }
    else
    {
        directory->entryAction(out);
        return directory;
    }
}

void Directory::rmAction(Printer &out)
{
    _debug("rmAction");

    for(auto it = m_elements.begin(); it != m_elements.end(); it ++)
    {
        it->second->rmAction(out);
        _remove(it->second->name());
    }
}

int Directory::isRemovable(Printer &out, const std::string &arg)
{
    _debug("isRemovable");

    if(arg == "-r")
    {
        int removable = 1;
        for(auto it = m_elements.begin(); it != m_elements.end(); it ++)
        {
            removable &= it->second->isRemovable(out, arg);
        }
        return removable;
    }
    else
    {
        out.println("rm: cannot remove 'truc': Is a directory");
        return 0;
    }
}

void Directory::executeCommand(Printer &out, const std::string &command)
{
    std::stringstream ss(command);
    std::string token;

    std::getline(ss, token, ' ');
    if(token == "ls")
    {
        lsElements(out);
    }
    else if(token == "mkdir")
    {
        while(std::getline(ss, token, ' '))
            mkdirAction(out, token);
    }
    else if(token == "rm")
    {
        while(std::getline(ss, token, ' '))
            rmElement(out, token, "-r");
    }
    else if(token == "pwd")
    {
        pwdAction(out);
    }
    else
    {
        out.println("Unknown command " + token);
    }
}

void Directory::mkdirAction(Printer &out, const std::string &name)
{
    _debug("mkdirAction " + name);

    auto it = m_elements.find(name);
    if(it == m_elements.end())
    {
        _debug("OK to create new dir");
        DirectoryPtr directory = new Directory(this, name);
        m_elements[name] = directory;
        m_directories[name] = directory;
    }
    else
    {
        out.println("mkdir: cannot create directory ‘" + name + "’: File exists");
    }
}

void Directory::pwdAction(Printer &out)
{
    out.println(path());
}

void Directory::_remove(const std::string name)
{
    {
        auto it = m_elements.find(name);
        if(it != m_elements.end())
        {
            m_elements.erase(it);
            delete it->second;
        }
    }
    {
        auto it = m_directories.find(name);
        if(it != m_directories.end())
        {
            m_directories.erase(it);
        }
    }
}

FileElementPtr Directory::_find(const std::string name)
{
    FileElementPtr found = nullptr;
    auto it = m_elements.find(name);
    if(it != m_elements.end()) found = it->second;
    return found;
}

DirectoryPtr Directory::_findDirectory(const std::string name)
{
    DirectoryPtr found = nullptr;
    auto it = m_directories.find(name);
    if(it != m_directories.end()) found = it->second;
    return found;
}

std::string Directory::_className()
{
    return "Directory";
}
