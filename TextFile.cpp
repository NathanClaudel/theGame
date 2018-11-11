#include "TextFile.h"

TextFile::TextFile(DirectoryPtr parent,
                   const std::string &name,
                   const std::string &content) :
    FileElement (parent, name),
    m_content(content)
{

}
