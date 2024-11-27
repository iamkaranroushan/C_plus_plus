#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Reading a binary file
    std::fstream bin_file("bin.bin", std::ios::binary | std::ios::in);

    if (bin_file.is_open()) {
        // Move the cursor to the end to determine the file size
        bin_file.seekg(0, std::ios::end);
        size_t file_size = bin_file.tellg();
        bin_file.seekg(0, std::ios::beg);

        
        std::vector<char> buffer(file_size);
        bin_file.read(buffer.data(), file_size);
        bin_file.close();

        
        std::cout << "Raw binary data:\n";
        for (unsigned char byte : buffer) {  
            std::cout << std::hex << static_cast<int>(byte) << " ";
        }
        std::cout << std::dec << std::endl; 
    } else {
        std::cerr << "Error opening the file.\n";
    }

    return 0; 
}
