#pragma once

#include <string>

class CompressionEngine {

public:

    static void saveCompressedFile(
        const std::string& encodedText,
        const std::string& outputPath
    );
};