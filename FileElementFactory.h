#ifndef FILEELEMENTFACTORY_H
#define FILEELEMENTFACTORY_H

#include <string>
#include <fstream>

#include "PtrDefinition.h"

class FileElementFactory
{
public:
    static DirectoryPtr readObject(const std::string &fileName, DirectoryPtr parent = nullptr);
    static FileElementPtr readObject(std::ifstream &in, DirectoryPtr parent);
};

#endif // FILEELEMENTFACTORY_H
