#include "HuffmanTree.hpp"

#include <iostream>

HuffmanNode* HuffmanTree::buildTree(
    const std::unordered_map<char, int>&
    frequencyTable
) {

    std::priority_queue<
        HuffmanNode*,
        std::vector<HuffmanNode*>,
        CompareNodes
    > minHeap;

    for (const auto& pair : frequencyTable) {

        minHeap.push(

            new HuffmanNode(
                pair.first,
                pair.second
            )
        );
    }

    while (minHeap.size() > 1) {

        HuffmanNode* left =
            minHeap.top();

        minHeap.pop();

        HuffmanNode* right =
            minHeap.top();

        minHeap.pop();

        HuffmanNode* mergedNode =
            new HuffmanNode(
                '\0',
                left->frequency +
                right->frequency
            );

        mergedNode->left = left;
        mergedNode->right = right;

        minHeap.push(mergedNode);
    }

    return minHeap.top();
}

void HuffmanTree::printTree(
    HuffmanNode* root,
    std::string code
) {

    if (root == nullptr) {
        return;
    }

    if (root->character != '\0') {

        std::cout
            << root->character
            << " : "
            << code
            << std::endl;
    }

    printTree(
        root->left,
        code + "0"
    );

    printTree(
        root->right,
        code + "1"
    );
}