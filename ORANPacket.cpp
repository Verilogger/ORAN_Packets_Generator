#include "ORANPacket.h"

ORANPacket::ORANPacket(int nrbPerPacket) : nrbPerPacket(nrbPerPacket) {}

std::vector<uint8_t> ORANPacket::generatePacket(const std::vector<std::pair<int, int>>& iqSamples) {
    std::vector<uint8_t> packet;

    // Logic to populate the ORAN packet with IQ samples
    for (int i = 0; i < nrbPerPacket && i < iqSamples.size(); ++i) {
        packet.push_back(static_cast<uint8_t>(iqSamples[i].first));
        packet.push_back(static_cast<uint8_t>(iqSamples[i].second));
    }

    return packet;
}
