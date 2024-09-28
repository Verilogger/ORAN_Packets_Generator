#include "Utils.h"
#include <sstream>
#include <iomanip>

std::string intToHex(uint32_t value, size_t width) {
    std::stringstream ss;
    ss << std::setw(width) << std::setfill('0') << std::hex << value;
    return ss.str();
}

uint32_t calculateCRC32(const std::string& data) {
    uint32_t crc = 0xFFFFFFFF;
    for (char c : data) {
        crc ^= c;
        for (int i = 0; i < 8; ++i) {
            if (crc & 1) crc = (crc >> 1) ^ 0xEDB88320;
            else crc >>= 1;
        }
    }
    return ~crc;
}
