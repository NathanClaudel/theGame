#include "Politeness.h"
#include <vector>
#include <time.h>
#include <string.h>

void Politeness::bePolite(std::ostream &out)
{
    std::vector<std::string> unpoliteAnswers = {"Try again when you're polite.",
                                                "So rude.",
                                                "You could just ask politely.",
                                                "* sigh *",
                                                "No way. I won't run.",
                                                "Who raised you like that ?"};
    srand(static_cast<unsigned int>(clock()));
    out << "\n\033[1;31m"
        << unpoliteAnswers.at(static_cast<unsigned int>(rand()) % unpoliteAnswers.size())
        << "\033[0m\n\n";
}

void Politeness::politeTest(int argc, char* argv[], std::ostream &out)
{
    if(argc > 2)
    {
        std::cout << "You're asking too much." << std::endl;
        exit(-1);
    }

    if(argc < 2 || 0 != strcmp(argv[1], "please"))
    {
        bePolite(out);
        exit(-1);
    }
}
