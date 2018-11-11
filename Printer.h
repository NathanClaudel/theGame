#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>

class Printer
{
public:

    enum
    {
        RED,
        BLUE,
        GREEN,
        YELLOW
    }
    typedef Color;

    static const int VERY_QUICK = 5000;
    static const int QUICK = 50000;
    static const int MEDIUM = 100000;
    static const int SLOW = 500000;
    static const int VERY_SLOW = 1000000;

    Printer(std::ostream &out);
    void print(const std::string &string);
    void println(const std::string &string);
    void print(unsigned int delay, const std::string &string);
    void println(unsigned int delay, const std::string &string);
    void print(unsigned int delay, Color color, const std::string &string);
    void println(unsigned int delay, Color color, const std::string &string);
    void endl();

private:
    static std::string _colorCode(Color color);

    std::ostream &m_out;
};

#endif // PRINTER_H
