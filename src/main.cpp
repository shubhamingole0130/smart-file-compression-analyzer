#include <iostream>

#include "FileManager.hpp"
#include "FrequencyAnalyzer.hpp"
#include "HuffmanTree.hpp"

int main() {

    try {

        std::string content =
            FileManager::readFile(
                "../data/input/sample.txt"
            );

        auto frequencyTable =
            FrequencyAnalyzer::
            buildFrequencyTable(
                content
            );

        HuffmanNode* root =
            HuffmanTree::buildTree(
                frequencyTable
            );

        HuffmanTree::printTree(root);

    } catch (const std::exception& error) {

        std::cout
            << error.what()
            << std::endl;
    }

    return 0;
}