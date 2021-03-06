#include "FileElementFactory.h"
#include "FileElement.h"
#include "Directory.h"
#include "RootDirectory.h"
#include "TextFile.h"
#include "ProgramLauncher.h"
#include "UiLauncher.h"

DirectoryPtr FileElementFactory::readObject(const std::string &fileName, DirectoryPtr parent)
{
    std::ifstream in(fileName);
    DirectoryPtr dir = nullptr;
    if(in.is_open())
    {
        dir = dynamic_cast<DirectoryPtr>(readObject(in, parent));
    }
    else
    {
        std::cout << "Could not open file " << fileName;
    }
    in.close();
    return dir;
}

FileElementPtr FileElementFactory::readObject(std::ifstream &in,
                                              DirectoryPtr parent)
{
    if(in.eof())
    {
        return nullptr;
    }

    std::string className;
    std::getline(in, className);

    if(className == "FileElement")
    {
        return FileElement::readObject(in, parent);
    }
    else if(className == "Directory")
    {
        return Directory::readObject(in, parent);
    }
    else if(className == "RootDirectory")
    {
        return RootDirectory::readObject(in);
    }
    else if(className == "TextFile")
    {
        return TextFile::readObject(in, parent);
    }
    else if(className == "ProgramLauncher")
    {
        return ProgramLauncher::readObject(in, parent);
    }
    else if(className == "UiLauncher")
    {
        return UiLauncher::readObject(in, parent);
    }

    return nullptr;
}
