#pragma once

#include <unordered_map>
#include <string>

#include "HuffmanNode.hpp"

class HuffmanCoder {

public:

    static void generateCodes(
        HuffmanNode* root,
        std::string currentCode,
        std::unordered_map<char, std::string>&
        huffmanCodes
    );

    static std::string encodeText(
        const std::string& text,
        const std::unordered_map<char,
        std::string>& huffmanCodes
    );
};