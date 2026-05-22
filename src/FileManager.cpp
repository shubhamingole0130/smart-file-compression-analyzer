#include "FileManager.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileManager::readFile(
    const std::string& filePath
) {

    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {

        throw std::runtime_error(
            "Failed to open file: " + filePath
        );
    }

    std::stringstream buffer;

    buffer << inputFile.rdbuf();

    return buffer.str();
}

void FileManager::writeFile(
    const std::string& filePath,
    const std::string& content
) {

    std::ofstream outputFile(filePath);

    if (!outputFile.is_open()) {

        throw std::runtime_error(
            "Failed to write file: " + filePath
        );
    }

    outputFile << content;
}