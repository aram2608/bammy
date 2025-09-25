#include "fastx.hpp"

FastIO::FastIO() {}

// Function to slurp a files contents
std::string FastIO::slurp_file(const std::string &filename) {
    // We first create an ifstream object called fastq
    std::ifstream fastq(filename);

    // Test to ensure file can open, otherwise assume bad file and return an
    // empty string
    if (!fastq.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;

        // Return empty string on failure
        return "";
    }

    // Read entire file into string using iterators
    std::string content((std::istreambuf_iterator<char>(fastq)),
                        std::istreambuf_iterator<char>());

    // Close file to prevent leaks
    fastq.close();
    return content;
}
