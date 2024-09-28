# ORAN_Packets_Generator


This project is basically an  extension for the Ethernet packet generator project I implemented a week ago. My focus is now on Milestone 2, which enhances the payload to include eCPRI headers and O-RAN packets. 

## Overview

The objective of this project is to generate Ethernet packets based on specified configurations and stream IQ samples in compliance with O-RAN standards. 

### Milestone 1

In Milestone 1, the following features were implemented:

- **Ethernet Packet Generation**: The application generates Ethernet packets and dumps them into a text file.
- **Streaming Duration**: Packets are generated for a specified streaming duration, defined in a setup file.
- **Packet Alignment**: Ethernet packets are 4-byte aligned, with Inter-Frame Gaps (IFGs) used as padding.
- **Packet Structure**: The packet generation process follows these steps:
  1. Preamble
  2. Start Frame Delimiter (SFD)
  3. Destination Address
  4. Source Address
  5. Ethernet Type
  6. Payload
  7. CRC
  8. Handling streaming time and IFGs

### Milestone 2

Milestone 2 focuses on enhancing the Ethernet payload:

- **eCPRI and O-RAN Integration**: The Ethernet payload now contains eCPRI, with the eCPRI payload including the O-RAN user plane.
- **IQ Samples**: IQ samples are included in the O-RAN user plane packet, sourced from a specified text file (`iq_file.txt`).
- **File Looping**: If more IQ samples are required than available in the input file, the program loops back to the beginning of the file.

#### eCPRI Header Structure

- The first byte of eCPRI will be a dummy value.
- `eCPRI.Message`: Set to `0x00`, representing user plane.
- `eCPRI.PC_RTC`: Fixed value `0x00`.
- `eCPRI.SeqId`: Starts from `0` and increments with each packet, resetting at `255`.

### Setup File Configuration for Milestone 2

The setup file includes parameters for the packet generation process:

1. `Eth.LineRate`: Transmit rate in Gbps.
2. `Eth.CaptureSizeMs`: Duration for which frames are generated (e.g., 10 ms).
3. `Eth.MinNumOfIFGsPerPacket`: Minimum number of IFGs after each packet.
4. `Eth.DestAddress`: Destination address (e.g., `0x010101010101`).
5. `Eth.SourceAddress`: Source address (e.g., `0x333333333333`).
6. `Eth.MaxPacketSize`: Maximum packet size in bytes.
7. `Oran.SCS`: Control plane indicator.
8. `Oran.MaxNRB`: Range from 0 to 255.
9. `Oran.NrbPerPacket`: Resource blocks in one packet.
10. `Oran.PayloadType`: Fixed or random payload type.
11. `Oran.Payload`: Name of the text file for IQ samples.


## How to Use

1. Prepare the setup file with the required configurations.
2. Ensure `iq_file.txt` is available in the specified path.
3. Open the command prompt and navigate to the project folder path.
4. Compile the program using the following command:

   ```bash
   g++ main.cpp EthernetPacket.cpp eCPRIPacket.cpp FileWriter.cpp IQSampleReader.cpp ORANPacket.cpp PacketConfig.cpp Utils.cpp -o program_output
   ```
5. Wait for the executable to be created, then run the program with the following command:
    ```bash
   program_output.exe <configuration_file_name> <text_file_in_which_the_packets_will_be_dumped>
    ```

## Useful Information
**Documentation**: Refer to the [O-RAN SC documentation](https://docs.o-ran-sc.org/projects/o-ran-sc-o-du-phy/en/latest/Transport-Layer-and-ORAN-Fronthaul-Protocol-Implementation_fh.html#introduction) for protocol standards and implementation guidance.

