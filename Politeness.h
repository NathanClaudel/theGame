#ifndef POLITENESS_H
#define POLITENESS_H

#include "Printer.h"

class Politeness
{
    public:
        static void bePolite(Printer &out);
        static void politeTest(int argc, char* argv[], Printer &out);
};

#endif // POLITENESS_H
