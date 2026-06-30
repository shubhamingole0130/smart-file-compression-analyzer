#include "DecompressionEngine.hpp"

std::string
DecompressionEngine::decodeText(

    const std::string&
    encodedText,

    HuffmanNode*
    root
) {

    std::string decoded;

    HuffmanNode*
    current =
    root;

    for (

        char bit :
        encodedText
    ) {

        if (

            bit ==
            '0'
        ) {

            current =
            current
            ->left;
        }

        else {

            current =
            current
            ->right;
        }

        if (

            current->left
            ==
            nullptr

            &&

            current->right
            ==
            nullptr
        ) {

            decoded +=
            current
            ->character;

            current =
            root;
        }
    }

    return decoded;
}