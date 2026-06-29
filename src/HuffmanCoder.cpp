#include "HuffmanCoder.hpp"

void HuffmanCoder::generateCodes(
    HuffmanNode* root,
    std::string currentCode,
    std::unordered_map<char, std::string>&
    huffmanCodes
) {

    if (root == nullptr) {
        return;
    }

    if (root->character != '\0') {

        huffmanCodes[
            root->character
        ] = currentCode;
    }

    generateCodes(
        root->left,
        currentCode + "0",
        huffmanCodes
    );

    generateCodes(
        root->right,
        currentCode + "1",
        huffmanCodes
    );
}

std::string HuffmanCoder::encodeText(
    const std::string& text,
    const std::unordered_map<char,
    std::string>& huffmanCodes
) {

    std::string encodedText;

    for (char character : text) {

        encodedText +=
            huffmanCodes.at(character);
    }

    return encodedText;
}