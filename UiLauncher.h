#ifndef UILAUNCHBUTTON_H
#define UILAUNCHBUTTON_H

#include "ProgramLauncher.h"

class UiLauncher : public ProgramLauncher
{
public:
    UiLauncher(DirectoryPtr parent, const std::string &name);

    virtual void executeAction(Printer &out) override;

    static FileElementPtr readObject(std::ifstream &in, DirectoryPtr parent);

};

#endif // UILAUNCHBUTTON_H
