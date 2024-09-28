// This file handles reading the configuration file and storing relevant values, including Ethernet and O-RAN-specific parameters.

#ifndef PACKETCONFIG_H
#define PACKETCONFIG_H

#include <string>

class PacketConfig {
public:
    bool loadConfig(const std::string& configFilePath);
    
    uint32_t lineRate;
    uint32_t captureSizeMs;
    uint8_t minNumOfIFGs;
    std::string destAddress;
    std::string srcAddress;
    uint32_t maxPacketSize;
    uint32_t scs;
    uint32_t maxNrb;
    uint32_t nrbPerPacket;
    std::string payloadType;
    std::string payloadFile;

private:
    bool parseLine(const std::string& line);
};

#endif
