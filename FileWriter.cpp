#include "FileWriter.h"
#include <iostream>

FileWriter::FileWriter(const std::string& filePath) {
    outputFile.open(filePath);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file: " << filePath << std::endl;
    }
}

FileWriter::~FileWriter() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void FileWriter::write(const std::string& data) {
    if (outputFile.is_open()) {
        std::cout << "Writing data: " << data << std::endl;
        outputFile << data << std::endl;  // Write data to the file
    } else {
        std::cerr << "Output file is not open for writing." << std::endl;
    }
}

void FileWriter::close() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}
