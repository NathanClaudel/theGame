#ifndef DEBUG_H
#define DEBUG_H

#include <string>

#ifdef DEBUG

void printDebug(const std::string &message)
{
    std::cout << "\033[1;33m"
              << message
              << "\033[0m"
              << std::endl;
}

#else

void printDebug(const std::string &) {}

#endif

#endif // DEBUG_H
