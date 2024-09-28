#include "eCPRIPacket.h"

// Define the static members
const uint8_t eCPRIPacket::eCPRI_MESSAGE = 0x00; // Example value for eCPRI message type
const uint8_t eCPRIPacket::eCPRI_VERSION = 0x01; // Example value for eCPRI version
const uint8_t eCPRIPacket::eCPRI_PC_RTC = 0x00;  // Example value for PC RTC

// Constructor definition
eCPRIPacket::eCPRIPacket() {
    // Initialization code can go here if needed
}

std::vector<uint8_t> eCPRIPacket::generatePacket(const std::vector<uint8_t>& oranPayload, uint8_t seqId) {
    std::vector<uint8_t> packet;

    // Logic to generate the eCPRI packet
    packet.push_back(eCPRI_MESSAGE); // Add the eCPRI message type
    packet.push_back(eCPRI_VERSION);  // Add the eCPRI version
    packet.push_back(eCPRI_PC_RTC);   // Add PC RTC

    // Add the sequence ID
    packet.push_back(seqId); 

    // Append the O-RAN payload
    packet.insert(packet.end(), oranPayload.begin(), oranPayload.end());

    return packet;
}
