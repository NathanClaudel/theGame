#include <unistd.h>
#include <iostream>
#include "Printer.h"

Printer::Printer(std::ostream &out) :
    m_out(out)
{

}

void Printer::print(const std::string &string)
{
    m_out << string;
    m_out.flush();
}

void Printer::println(const std::string &string)
{
    print(string);
    endl();
}

void Printer::print(unsigned int delay, const std::string &string)
{
    for(unsigned int i = 0; i < string.size(); i ++)
    {
        m_out << string[i];
        m_out.flush();
        usleep(delay);
    }
}

void Printer::println(unsigned int delay, const std::string &string)
{
    print(delay, string);
    endl();
}

void Printer::print(unsigned int delay, Printer::Color color, const std::string &string)
{
    m_out << "\033[1;" +  _colorCode(color) + "m";
    print(delay, string);
    m_out << "\033[0m";
}

void Printer::println(unsigned int delay, Printer::Color color, const std::string &string)
{
    print(delay, color, string);
    endl();
}

void Printer::endl()
{
    m_out << std::endl;
}

std::string Printer::_colorCode(Printer::Color color)
{
    switch(color)
    {
    case(RED): return "31";
    case(GREEN): return "32";
    case(YELLOW): return "33";
    case(BLUE): return "34";
    }
    return "";
}

