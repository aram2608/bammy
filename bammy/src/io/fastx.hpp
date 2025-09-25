#ifndef FASTX_HPP
#define FASTX_HPP

#include "zlib.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct FastIO {
    FastIO() = default;

    void slurp_file(const std::string &filename);
    bool is_gzip(const std::string &filename);
};

#endif