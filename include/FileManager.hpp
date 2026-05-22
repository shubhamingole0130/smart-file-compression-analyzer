#pragma once

#include <string>

class FileManager {
public:

    static std::string readFile(
        const std::string& filePath
    );

    static void writeFile(
        const std::string& filePath,
        const std::string& content
    );
};