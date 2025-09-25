#ifndef BAMMY_HPP
#define BAMMY_HPP

#include "../io/fastx.hpp"

struct Bammy {
    Bammy();

    static void run(int argc, char **argv);
    static void help();
};

#endif