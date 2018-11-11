#include "RootDirectory.h"
#include "FileElementFactory.h"

RootDirectory::RootDirectory(const std::string name) :
    Directory (nullptr, name)
{

}

RootDirectory::~RootDirectory()
{

}

void RootDirectory::outAction(Printer &out)
{
    out.println(Printer::MEDIUM, "Where do you think you are going ?");
}

DirectoryPtr RootDirectory::readObject(std::ifstream &in)
{
    std::string name;
    std::getline(in, name);

    RootDirectory *directory = new RootDirectory(name);
    FileElementPtr element;
    do
    {
        element = FileElementFactory::readObject(in, directory);
        directory->_add(element);
    }
    while(element != nullptr);

    return directory;
}

std::string RootDirectory::_className()
{
    return "RootDirectory";
}

