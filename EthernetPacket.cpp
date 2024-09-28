#include "EthernetPacket.h"
#include "Utils.h"
#include "eCPRIPacket.h"
#include "ORANPacket.h"
#include "IQSampleReader.h"
#include <sstream>
#include <iostream>

// Ethernet frame constants
const std::string PREAMBLE = "FB555555555555D5";
const uint32_t CRC_WIDTH = 8;

EthernetPacket::EthernetPacket(const PacketConfig& config, FileWriter& fileWriter)
    : config(config), fileWriter(fileWriter), iqReader(config.payloadFile), seqId(0) {}

void EthernetPacket::startGenerating() {
    uint32_t totalPackets = (config.lineRate * 1000000) * config.captureSizeMs / (config.maxPacketSize * 8);
    std::cout << "Total packets to generate: " << totalPackets << std::endl;

    for (uint32_t i = 0; i < totalPackets; ++i) {
        generateSinglePacket();
    }
}

void EthernetPacket::generateSinglePacket() {
    std::stringstream packetStream;
    packetStream << PREAMBLE;
    packetStream << config.destAddress.substr(2) << config.srcAddress.substr(2);
    packetStream << "0800";  // Ethernet type (customized for eCPRI)

    // Generate payload that includes the eCPRI header and O-RAN data
    std::string payload = generatePayload();
    packetStream << payload;

    std::string packetData = packetStream.str();
    uint32_t crc = calculateCRC32(packetData);
    packetStream << intToHex(crc, CRC_WIDTH);
    
    // Debug output
    std::cout << "Generated packet: " << packetStream.str() << std::endl;
    
    // Write packet to file
    fileWriter.write(packetStream.str());
}

std::string EthernetPacket::generatePayload() {
    // Read IQ samples for O-RAN packet generation
    std::vector<std::pair<int, int>> iqSamples;
    std::string iqSampleLine;
    
    while ((iqSampleLine = iqReader.getNextIqSample()) != "00") {
        std::istringstream iss(iqSampleLine);
        int i, q;
        if (iss >> i >> q) {
            iqSamples.emplace_back(i, q);
        }
    }

    // Create ORAN packet with the IQ samples
    ORANPacket oranPacket(config.nrbPerPacket); // Ensure nrbPerPacket is defined in your config
    std::vector<uint8_t> oranPayload = oranPacket.generatePacket(iqSamples);
    
    // Create eCPRI packet including ORAN payload
    eCPRIPacket eCPRI;
    std::vector<uint8_t> eCPRIHeader = eCPRI.generatePacket(oranPayload, seqId++); // Increment sequence ID
    
    // Convert eCPRIHeader to string for Ethernet payload
    std::string payload(reinterpret_cast<const char*>(eCPRIHeader.data()), eCPRIHeader.size());
    
    return payload;
}
