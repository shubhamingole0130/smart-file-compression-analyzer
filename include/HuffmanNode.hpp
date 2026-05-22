#pragma once

class HuffmanNode {

public:

    char character;
    int frequency;

    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(
        char character,
        int frequency
    ) {

        this->character = character;
        this->frequency = frequency;

        left = nullptr;
        right = nullptr;
    }
};