#ifndef ECPRIPACKET_H
#define ECPRIPACKET_H

#include <vector>
#include <cstdint>

class eCPRIPacket {
public:
    eCPRIPacket(); // Constructor declaration
    std::vector<uint8_t> generatePacket(const std::vector<uint8_t>& oranPayload, uint8_t seqId);

private:
    static const uint8_t eCPRI_MESSAGE;
    static const uint8_t eCPRI_VERSION;
    static const uint8_t eCPRI_PC_RTC;
};

#endif // ECPRIPACKET_H
