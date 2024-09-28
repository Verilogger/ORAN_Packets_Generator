#include <iostream>
#include "PacketConfig.h"
#include "EthernetPacket.h"
#include "FileWriter.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <configuration file> <output file>\n";
        return 1;
    }

    std::string configFilePath = argv[1];
    std::string outputFilePath = argv[2];

    std::cout << "\nLoading configuration from: " << configFilePath << std::endl;
    std::cout << "---------------------------------------------------------\n";

    // Load configuration
    PacketConfig config;
    if (!config.loadConfig(configFilePath)) {
        std::cerr << "Failed to load configuration file.\n";
        return 1;
    }

    // Set up file writer
    FileWriter fileWriter(outputFilePath);
    std::cout << "---------------------------------------------------------\n";
    std::cout << "\n\nWriting output to: " << outputFilePath << std::endl;
    std::cout << "---------------------------------------------------------\n";

    // Start packet generation
    EthernetPacket packetGenerator(config, fileWriter);
    packetGenerator.startGenerating();  // Generating O-RAN packets

    std::cout << "Packet generation completed.\n";
    std::cout << "You can now see the packets in: " << outputFilePath << std::endl;
    std::cout << "I'm glad you used my program ;), wish you a nice day!\n";
    std::cout << "---------------------------------------------------------\n";
    return 0;
}
