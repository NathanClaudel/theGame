#ifndef ROOTDIRECTORY_H
#define ROOTDIRECTORY_H

#include "Directory.h"

class RootDirectory : public Directory
{
public:
    RootDirectory(const std::string name);
    virtual ~RootDirectory() override;

    virtual void outAction(Printer &out) override;

    static DirectoryPtr readObject(std::ifstream &in);

protected:
    virtual std::string _className() override;
};

#endif // ROOTDIRECTORY_H
