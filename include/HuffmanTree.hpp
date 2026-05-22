#pragma once

#include <unordered_map>
#include <queue>
#include <string>

#include "HuffmanNode.hpp"
#include "CompareNodes.hpp"

class HuffmanTree {

public:

    static HuffmanNode* buildTree(
        const std::unordered_map<char, int>&
        frequencyTable
    );

    static void printTree(
        HuffmanNode* root,
        std::string code = ""
    );
};