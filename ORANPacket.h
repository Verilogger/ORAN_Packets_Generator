#ifndef ORAN_PACKET_H
#define ORAN_PACKET_H

#include <vector>
#include <cstdint>
#include <utility> // For std::pair

class ORANPacket {
public:
    ORANPacket(int nrbPerPacket);
    std::vector<uint8_t> generatePacket(const std::vector<std::pair<int, int>>& iqSamples);

private:
    int nrbPerPacket;
};

#endif // ORAN_PACKET_H
