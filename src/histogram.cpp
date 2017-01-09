#include "histogram.h"
#include <iostream>
#include <string>
#include <exception>
#include <streambuf>
#include <fstream>

/**
 * @brief Read a file
 * @param filename - The relative file path
 * @return A file as text
 */
std::string readFile(const std::string &filename);

std::string readFile(const std::string &filename) {
    std::ifstream ifs(filename);
    return std::string((std::istreambuf_iterator<char>(ifs)),
                       (std::istreambuf_iterator<char>()));
}

/**
 * Entry of the application
 */
int main(int argc, char *argv[]) {
    std::string file;
    if (argc < 3) {
        std::cerr << "No arguments received. "
                "You have to pass a file that should be inspected. "
                "This program now runs with `--file example.txt`" << std::endl;
        file = "example.txt";
    } else {
        file = argv[2];
    }
    histogram::draw(readFile(file));


}
