#include "FrequencyAnalyzer.hpp"

std::unordered_map<char, int>
FrequencyAnalyzer::buildFrequencyTable(
    const std::string& text
) {

    std::unordered_map<char, int>
    frequencyTable;

    for (char character : text) {

        frequencyTable[character]++;
    }

    return frequencyTable;
}