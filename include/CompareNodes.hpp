#pragma once

#include "HuffmanNode.hpp"

class CompareNodes {

public:

    bool operator()(
        HuffmanNode* left,
        HuffmanNode* right
    ) {

        return left->frequency >
               right->frequency;
    }
};