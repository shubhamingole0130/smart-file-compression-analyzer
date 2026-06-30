#pragma once

#include <string>

#include "HuffmanNode.hpp"

class DecompressionEngine {

public:

    static std::string
    decodeText(

        const std::string&
        encodedText,

        HuffmanNode*
        root
    );
};