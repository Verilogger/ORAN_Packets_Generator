// This remains the same as milestone 1, handling the writing of packets to a file.

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <fstream>
#include <string>

class FileWriter {
public:
    FileWriter(const std::string& filePath);
    ~FileWriter();
    
    void write(const std::string& data);
    void close();

private:
    std::ofstream outputFile;
};

#endif
