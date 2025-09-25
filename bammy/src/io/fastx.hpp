#ifndef FASTX_HPP
#define FASTX_HPP

#include <fstream>
#include <iostream>
#include <string>

struct FastIO {
    FastIO();

    static std::string slurp_file(const std::string &filename);
};

#endif