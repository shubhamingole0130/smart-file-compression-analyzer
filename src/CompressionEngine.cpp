#include "CompressionEngine.hpp"

#include <fstream>
#include <bitset>
#include <iostream>

void CompressionEngine::saveCompressedFile(
    const std::string& encodedText,
    const std::string& outputPath
) {

    std::ofstream output(
        outputPath,
        std::ios::binary
    );

    if (!output.is_open()) {

        throw std::runtime_error(
            "Cannot create compressed file"
        );
    }

    std::string byte;

    for (char bit : encodedText) {

        byte += bit;

        if (byte.size() == 8) {

            char compressedByte =
                static_cast<char>(
                    std::bitset<8>(
                        byte
                    ).to_ulong()
                );

            output.write(
                &compressedByte,
                1
            );

            byte.clear();
        }
    }

    if (!byte.empty()) {

        while (
            byte.size() < 8
        ) {

            byte += "0";
        }

        char compressedByte =
            static_cast<char>(
                std::bitset<8>(
                    byte
                ).to_ulong()
            );

        output.write(
            &compressedByte,
            1
        );
    }

    output.close();

    std::cout
        << "\nCompression Complete\n";
}