#ifndef ROOTDIRECTORY_H
#define ROOTDIRECTORY_H

#include "Directory.h"

class RootDirectory : public Directory
{
public:
    RootDirectory();
    virtual ~RootDirectory() override;

protected:
    virtual void outAction(Printer &out) override;
};

#endif // ROOTDIRECTORY_H
