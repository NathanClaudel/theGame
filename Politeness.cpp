#include "Politeness.h"
#include <vector>
#include <time.h>
#include <string.h>

void Politeness::bePolite(Printer &out)
{
    std::vector<std::string> unpoliteAnswers = {"Try again when you're polite.",
                                                "So rude.",
                                                "You could just ask politely.",
                                                "* sigh *",
                                                "No way. I won't run.",
                                                "Who raised you like that ?"};
    srand(static_cast<unsigned int>(clock()));
    out.println(Printer::MEDIUM, Printer::RED,
                unpoliteAnswers.at(static_cast<unsigned int>(rand()) % unpoliteAnswers.size()));
}

void Politeness::politeTest(int argc, char* argv[], Printer &out)
{
    if(argc > 2)
    {
        out.println(10000, Printer::RED,
                    "You're trying too hard.");
        exit(-1);
    }

    if(argc < 2 || 0 != strcmp(argv[1], "please"))
    {
        bePolite(out);
        exit(-1);
    }
}
