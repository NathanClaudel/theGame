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

void Directory::entryAction(std::ostream &)
{

}

void Directory::outAction(std::ostream &)
{

}

void Directory::lsElements(std::ostream &out)
{
    _debug("lsAction");

    for(auto it = m_elements.begin(); it != m_elements.end(); it ++)
    {
        it->second->lsAction(out);
        out << std::endl;
    }
}

void Directory::rmElement(std::ostream &out, const std::string &name, const std::string args)
{
    FileElementPtr element = _find(name);
    if(element == nullptr)
    {
        out << "rm: cannot remove '" << name << "': No such file or directory"
            << std::endl;
    }
    else
    {
        if(element->isRemovable(out, args))
        {
            _remove(element->name());
        }
    }
}

DirectoryPtr Directory::cdElement(std::ostream &out, const std::string name)
{
    if(name == "..")
    {
        outAction(out);
        return parent() == nullptr ? this : parent();
    }
    DirectoryPtr directory = _findDirectory(name);
    if(directory == nullptr)
    {
        out << "cd: " << name << ": No such file or directory";
        return this;
    }
    else
    {
        directory->entryAction(out);
        return directory;
    }
}

void Directory::rmAction(std::ostream &out)
{
    _debug("rmAction");

    for(auto it = m_elements.begin(); it != m_elements.end(); it ++)
    {
        it->second->rmAction(out);
        _remove(it->second->name());
    }
}

int Directory::isRemovable(std::ostream &out, const std::string &arg)
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
        out << "rm: cannot remove 'truc': Is a directory" << std::endl;
        return 0;
    }
}

void Directory::mkdirAction(std::ostream &out, const std::string &name)
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
        out << "mkdir: cannot create directory ‘" + name + "’: File exists" << std::endl;
    }
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
