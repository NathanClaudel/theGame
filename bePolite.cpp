#ifndef POLITE

#include <iostream>

#include "Politeness.h"

int main()
{
    Politeness::bePolite(*new Printer(std::cout));
}

#endif
