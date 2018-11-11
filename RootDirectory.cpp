#include "RootDirectory.h"

RootDirectory::RootDirectory() :
    Directory(nullptr, "~/game")
{

}

RootDirectory::~RootDirectory()
{

}

void RootDirectory::outAction(Printer &out)
{
    out.println(Printer::MEDIUM, "Where do you think you are going ?");
}

