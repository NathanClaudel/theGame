#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "PtrDefinition.h"
#include "FileElement.h"

class TextFile : FileElement
{
public:
    TextFile(DirectoryPtr parent,
             const std::string &name,
             const std::string &content);

    virtual void catAction(Printer &out) override;

    virtual void writeObject(std::ofstream &out) override;
    static FileElementPtr readObject(std::ifstream &in, DirectoryPtr parent);

protected:
    std::string _className() override;

private:
    std::string m_content;
};

#endif // TEXTFILE_H
