#include "UiLauncher.h"
#include "Directory.h"
#include "FileElementFactory.h"

UiLauncher::UiLauncher(DirectoryPtr parent, const std::string &name) :
    ProgramLauncher (parent, name, "xeyes", 10, Printer::SLOW)
{

}

void UiLauncher::executeAction(Printer &out)
{
    out.println(Printer::QUICK, Printer::GREEN, "LAUNCHING UI");

#ifndef DEBUG
    ProgramLauncher::executeAction(out);

    out.println(Printer::MEDIUM, "Are you serious ?\n"
                               "Did you serouisly believe this program had an UI ?\n"
                               "Where do' you think you are ?");
    out.println(Printer::VERY_SLOW, "WINDOWS ?");
    out.println(Printer::MEDIUM, "\nIt's linux here, and no one will come to hold "
                                 "your hand.");
#endif

    parent()->_add(FileElementFactory::readObject("file2", parent()));
    out.println(Printer::QUICK, Printer::YELLOW, "\nA new folder appeared.");
}

FileElementPtr UiLauncher::readObject(std::ifstream &in, DirectoryPtr parent)
{
    std::string name;
    std::getline(in, name);

    return new UiLauncher(parent, name);
}
