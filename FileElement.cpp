#include "FileElement.h"
#include "Directory.h"
#include "Debug.h"

FileElement::FileElement(DirectoryPtr parent, const std::string name) :
    m_name(name),
    m_parent(parent)
{
    _debug("constructor");
}

FileElement::~FileElement()
{
    _debug("destructor");
}

const std::string &FileElement::path()
{
    std::string *path = new std::string("");
    FileElementPtr element = this;
    while(element != nullptr)
    {
        element = element->parent();
        *path = (element == nullptr ? "" : "/") + name() + *path;
    }
    return *path;
}

void FileElement::lsAction(Printer &out)
{
    out.println(m_name);
}

void FileElement::rmAction(Printer &)
{

}

void FileElement::catAction(Printer &)
{

}

int FileElement::isRemovable(Printer &, const std::string &)
{
    return 1;
}

void FileElement::writeObject(std::ofstream &out)
{
    out << _className() << std::endl;
    out << name() << std::endl;
}

FileElementPtr FileElement::readObject(std::ifstream &in, DirectoryPtr parent)
{
    std::string name;
    std::getline(in, name);

    return new FileElement(parent, name);
}

#ifdef DEBUG
void FileElement::_debug(const std::string &message)
{
    printDebug(_className() + " " + m_name + " : " + message);
}
#else
void FileElement::_debug(const std::string &) {}
#endif

std::string FileElement::_className()
{
    return "FileElement";
}
