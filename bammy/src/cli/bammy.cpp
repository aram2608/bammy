#include "bammy.hpp"

Bammy::Bammy() {}

void Bammy::run(int argc, char **argv) {
    bool show_help = false;
    std::string filename = "";
    FastIO fastio;
    /*
     * A simple parser for command line arguments
     * We iterate over all the arguments in the array and look for flags
     * We start from 1 to skip program name
     */
    for (int i = 1; i < argc; ++i) {
        // We store the argument as a string
        std::string arg = argv[i];

        // If the first argument matches help we show the help message
        if (arg == "--help" || arg == "-h") {
            show_help = true;
            // If the argument matches the file flag
        } else if (arg == "-i") {
            /*
             * We test if the current argument is less than the number of args
             * If the current argument is equal to the number of args then we
             * can assume no file was passed in
             */
            if (i + 1 < argc) {
                // We can then save the next argument as the filename
                filename = argv[++i];
                fastio.slurp_file(filename);
                // If not file is entered we can exit out
            } else {
                std::cerr << "Error: -i requires a filename." << std::endl;
                return;
            }
            // If the flag does not match any argument we can exit out
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            return;
        }
    }

    // A simple show help message
    if (show_help) {
        help();
    }
}

void Bammy::help() {
    std::cout << "Bammy read aligner\n";
    std::cout << "Usage: \n";
    std::cout << "--file /path/to/file/" << std::endl;
}
