// This header defines the Ethernet packet generator, including the handling of the O-RAN payload and IQ samples.

#ifndef ETHERNETPACKET_H
#define ETHERNETPACKET_H

#include <string>
#include <vector>
#include "PacketConfig.h"
#include "FileWriter.h"
#include "IQSampleReader.h"

class EthernetPacket {
public:
    EthernetPacket(const PacketConfig& config, FileWriter& fileWriter);
    void startGenerating();

private:
    void generateSinglePacket();
    std::string generatePayload();

    PacketConfig config;
    FileWriter& fileWriter;
    IQSampleReader iqReader;
    
    uint8_t seqId;  // Add this line to declare seqId
};

#endif // ETHERNETPACKET_H

