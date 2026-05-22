#pragma once

#include <unordered_map>
#include <string>

class FrequencyAnalyzer {

public:

    static std::unordered_map<char, int>
    buildFrequencyTable(
        const std::string& text
    );
};