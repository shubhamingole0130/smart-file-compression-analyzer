#pragma once

#include <string>

class Statistics {

public:

    static long getFileSize(
        const std::string& path
    );

    static void showReport(

        long original,

        long compressed,

        double timeTaken
    );
};