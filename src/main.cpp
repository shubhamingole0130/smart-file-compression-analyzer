#include <iostream>
#include "CompressionEngine.hpp"
#include "FileManager.hpp"
#include "FrequencyAnalyzer.hpp"
#include "HuffmanTree.hpp"
#include "DecompressionEngine.hpp"
#include "HuffmanCoder.hpp"

int main()
{

    try
    {

        std::string content =
            FileManager::readFile(
                "../data/input/sample.txt");

        auto frequencyTable =
            FrequencyAnalyzer::
                buildFrequencyTable(
                    content);

        HuffmanNode *root =
            HuffmanTree::buildTree(
                frequencyTable);

        std::unordered_map<
            char,
            std::string>
            huffmanCodes;

        HuffmanCoder::generateCodes(
            root,
            "",
            huffmanCodes);

        std::cout
            << "Huffman Codes:\n";

        for (const auto &pair :
             huffmanCodes)
        {

            std::cout
                << pair.first
                << " : "
                << pair.second
                << std::endl;
        }

        std::string encodedText =
            HuffmanCoder::encodeText(
                content,
                huffmanCodes);

        std::cout
            << "\nEncoded Text:\n";

        std::cout
            << encodedText
            << std::endl;
        CompressionEngine::
            saveCompressedFile(

                encodedText,

                "../data/output/compressed.huff");

        std::string
            decoded =

                DecompressionEngine::
                    decodeText(

                        encodedText,

                        root);

        std::cout

            << "\nDecoded:\n"

            << decoded

            << std::endl;
    }
    catch (const std::exception &error)
    {

        std::cout
            << error.what()
            << std::endl;
    }

    return 0;
}