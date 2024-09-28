// This new class is introduced to handle reading IQ samples from a file and ensuring they are correctly formatted for O-RAN packets.

#ifndef IQSAMPLEREADER_H
#define IQSAMPLEREADER_H

#include <string>
#include <fstream>

class IQSampleReader {
public:
    IQSampleReader(const std::string& filePath);
    std::string getNextIqSample();

private:
    std::ifstream iqFile;
};

#endif
