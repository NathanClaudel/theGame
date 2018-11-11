#ifndef ROOTDIRECTORY_H
#define ROOTDIRECTORY_H

#include "Directory.h"

class RootDirectory : public Directory
{
public:
    RootDirectory();

    virtual void outAction(std::ostream &out) override;
};

#endif // ROOTDIRECTORY_H
