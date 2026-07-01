#include "Statistics.hpp"

#include <iostream>
#include <fstream>

long Statistics::getFileSize(
    const std::string& path
) {

    std::ifstream file(
        path,
        std::ios::binary
    );

    file.seekg(
        0,
        std::ios::end
    );

    return file.tellg();
}

void Statistics::showReport(

    long original,

    long compressed,

    double timeTaken
) {

    double ratio =

        (
            100.0
            *

            compressed
        )

        /

        original;

    double saved =

        100.0
        -
        ratio;

    std::cout

    << "\n===== REPORT =====\n";

    std::cout

    << "Original: "

    << original

    << " bytes\n";

    std::cout

    << "Compressed: "

    << compressed

    << " bytes\n";

    std::cout

    << "Compression Ratio: "

    << ratio

    << "%\n";

    std::cout

    << "Space Saved: "

    << saved

    << "%\n";

    std::cout

    << "Execution Time: "

    << timeTaken

    << " ms\n";
}