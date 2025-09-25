#ifndef BAMMY_HPP
#define BAMMY_HPP

#include "../io/fastx.hpp"

struct Bammy {
    Bammy();

    void run(int argc, char **argv);
    void help();
};

#endif