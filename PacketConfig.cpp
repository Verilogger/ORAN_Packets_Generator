#include "PacketConfig.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool PacketConfig::loadConfig(const std::string& configFilePath) {
    std::ifstream configFile(configFilePath);
    if (!configFile.is_open()) {
        std::cerr << "Error: Could not open configuration file: " << configFilePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(configFile, line)) {
        if (!parseLine(line)) {
            std::cerr << "Error: Failed to parse line: " << line << std::endl;  // Debug output
            return false;
        }
    }

    configFile.close();
    return true;
}

bool PacketConfig::parseLine(const std::string& line) {
    std::istringstream iss(line);
    std::string key, value;

    // Read the key and value from the line
    if (std::getline(iss, key, '=') && std::getline(iss, value)) {
        // Trim leading and trailing spaces from the key and value
        key.erase(0, key.find_first_not_of(' ')); 
        key.erase(key.find_last_not_of(' ') + 1); 
        value.erase(0, value.find_first_not_of(' ')); 
        value.erase(value.find_last_not_of(' ') + 1);

        std::cout << "Parsed key: '" << key << "', value: '" << value << "'" << std::endl; // Debug output

        // Match the key to the corresponding member variable
        if (key == "Eth.LineRate") lineRate = std::stoi(value);
        else if (key == "Eth.CaptureSizeMs") captureSizeMs = std::stoi(value);
        else if (key == "Eth.MinNumOfIFGsPerPacket") minNumOfIFGs = std::stoi(value);
        else if (key == "Eth.DestAddress") destAddress = value;
        else if (key == "Eth.SourceAddress") srcAddress = value;
        else if (key == "Eth.MaxPacketSize") maxPacketSize = std::stoi(value);
        else if (key == "Oran.SCS") scs = std::stoi(value);
        else if (key == "Oran.MaxNrb") maxNrb = std::stoi(value);
        else if (key == "Oran.NrbPerPacket") nrbPerPacket = std::stoi(value);
        else if (key == "Oran.PayloadType") payloadType = value;
        else if (key == "Oran.Payload") payloadFile = value;
        else return false; // Key not recognized

        return true; // Successful parsing
    }
    return false; // Failed to read key and value
}

