#include "TextFile.h"

TextFile::TextFile(DirectoryPtr parent,
                   const std::string &name,
                   const std::string &content) :
    FileElement (parent, name),
    m_content(content)
{

}

void TextFile::catAction(Printer &out)
{
    out.println(m_content);
}

void TextFile::writeObject(std::ofstream &out)
{
    FileElement::writeObject(out);
    out << m_content;
    out << "#" << std::endl;
}

FileElementPtr TextFile::readObject(std::ifstream &in, DirectoryPtr parent)
{
    std::string name;
    std::getline(in, name);

    std::string content;
    std::getline(in, content, '#');

    std::string tmp;
    std::getline(in, tmp);

    return new TextFile(parent, name, content);
}

std::string TextFile::_className()
{
    return "TextFile";
}
