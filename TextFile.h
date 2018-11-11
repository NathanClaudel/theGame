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

private:
    std::string m_content;
};

#endif // TEXTFILE_H
