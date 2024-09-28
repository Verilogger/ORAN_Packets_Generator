#include "IQSampleReader.h"
#include <sstream>
#include <iostream>

IQSampleReader::IQSampleReader(const std::string& filePath) {
    iqFile.open(filePath);
    if (!iqFile.is_open()) {
        std::cerr << "Failed to open IQ sample file: " << filePath << std::endl;
    }
}

std::string IQSampleReader::getNextIqSample() {
    std::string line;
    if (std::getline(iqFile, line)) {
        return line;  // Return next line from the IQ sample file
    } else {
        return "00";  // If no more data, return a default value (all zeroes)
    }
}
