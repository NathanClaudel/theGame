#include "RootDirectory.h"

RootDirectory::RootDirectory() :
    Directory (nullptr, "~/game")
{

}

RootDirectory::~RootDirectory()
{

}

void RootDirectory::outAction(std::ostream &out)
{
    out << "Where do you think you're going ?";
}

