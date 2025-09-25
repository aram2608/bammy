#include "fastx.hpp"

// Function to slurp a files contents
void FastIO::slurp_file(const std::string &filename) {
    // We test if the file is a gzipped file
    if (is_gzip(filename)) {
        // We create a gzip object
        gzFile fastq_gz_file = gzopen(filename.c_str(), "rb");

        // We make sure we can open the file
        if (!fastq_gz_file) {
            std::cerr << "Error opening gzipped file" << std::endl;
            return;
        }

        // Buffer for reading lines
        char buffer[1024];
        std::string line;
        std::string id, sequence, optional_id, quality_scores;
        int line_count = 0;

        while (gzgets(fastq_gz_file, buffer, sizeof(buffer)) != Z_NULL) {
            line = buffer;
            line.erase(line.find_last_not_of("\r\n") +
                       1); // Remove newline characters

            line_count++;
             // Identifier line
            if (line_count % 4 == 1) {
                id = line;
            // Sequence line
            } else if (line_count % 4 == 2) {
                sequence = line;
            // Optional identifier line
            } else if (line_count % 4 == 3) {
                optional_id = line;
            // Quality scores line
            } else {
                quality_scores = line;

                // Process the complete FASTQ record
                std::cout << "ID: " << id << std::endl;
                std::cout << "Sequence: " << sequence << std::endl;
                std::cout << "Quality Scores: " << quality_scores << std::endl;
                std::cout << "---" << std::endl;
            }
        }
        // We close the file to prevent leaks
        gzclose(fastq_gz_file);
        return;
    // If not a gzip we assume its a standard text file
    } else {
        // We create an ifstream object
        std::ifstream fastq_file(filename);

        // We test if we can open the file
        if (!fastq_file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        std::string line;
        std::string id, sequence, optional_id, quality_scores;
        int line_count = 0;

        while (std::getline(fastq_file, line)) {
            line_count++;
             // Identifier line
            if (line_count % 4 == 1) {
                id = line;
             // Sequence line
            } else if (line_count % 4 == 2) {
                sequence = line;
             // Optional identifier line
            } else if (line_count % 4 == 3) {
                optional_id = line;
             // Quality scores line
            } else {
                quality_scores = line;

                // Process the complete FASTQ record
                std::cout << "ID: " << id << std::endl;
                std::cout << "Sequence: " << sequence << std::endl;
                std::cout << "Quality Scores: " << quality_scores << std::endl;
                std::cout << "---" << std::endl;
            }
        }
        // We close the file to prevent leaks
        fastq_file.close();
    }
}

bool FastIO::is_gzip(const std::string &filename) {
    // We create an ifstream object for our file
    std::ifstream file(filename, std::ios::binary);
    // Test to ensure file can open, otherwise assume bad file and return
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;
    }

    std::vector<unsigned char> magic_number(2);
    if (file.read(reinterpret_cast<char *>(magic_number.data()), 2)) {
        // Gzip magic number is 0x1f8b
        if (magic_number[0] == 0x1f && magic_number[1] == 0x8b) {
            return true;
        }
    }
    return false;
}
