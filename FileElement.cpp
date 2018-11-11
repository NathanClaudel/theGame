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
        *path = "/" + name() + *path;
        element = element->parent();
    }
    return *path;
}

void FileElement::lsAction(std::ostream &out)
{
    out << m_name;
}

void FileElement::rmAction(std::ostream &)
{

}

int FileElement::isRemovable(std::ostream &, const std::string &)
{
    return 1;
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
