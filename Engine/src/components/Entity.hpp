#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <picoPNG/src/picopng.hpp>
#include <fstream>
#include <exception>
#include <iostream>
#include <cstring>
/*----------------------------------------------------------------------------------------*/


namespace SalsaEngine {

struct Entity_t {

    explicit Entity_t(uint32_t width, uint32_t height) 
        : Width { width }, Height { height }
    {
        Sprite.resize(Width * Height);                                          // Vector's capacity now is sprite's resolution
    }

    explicit Entity_t(std::string pngFile) {
        std::vector<unsigned char> pixels {};
        unsigned long outWidth { 0UL }, outHeight { 0UL };

        // ifstream is RAII (auto destroyed when out of scope)
        try {
            std::ifstream file(pngFile, std::ios::binary);                      // using ifstream, "input file stream". C++ way of opening files. Because the file we want to open is a png and not a text file, we use ios::binary to get the bytes of the image

            std::vector<unsigned char> fileVector (
                std::istreambuf_iterator<char> { file },                        // begin iterator
                std::istreambuf_iterator<char> {}                               // end iterator (istreambuf_iterator default constructor points to the end of the stream, aka "eof" (end of file))
            );
            //                            same as "&fileVector[0]"
            decodePNG(pixels, outWidth, outHeight, fileVector.data(), fileVector.size());
            //       |  ^   out   ^   puts   ^   |

            Sprite.resize(pixels.size() / 4);                                   // From uint32_t size to char size
            std::memcpy(Sprite.data(), pixels.data(), pixels.size());           // Not a good solution because we are resizing twice and filling the memory with 0s, but it works for now

            // Sprite = std::vector<uint32_t> ( pixels.begin(), pixels.end() );    // Behind scenes, this creates a local vector variable, and uses std::move
            Width = outWidth; Height = outHeight;
        }
        catch (...) {
            std::cout << "Tried to read PNG file but something failed. Check PNG format.\n";
        }
    }


    uint32_t XPos { 0 }, YPos { 0 };
    uint32_t Width { 0 }, Height { 0 };

    std::vector<uint32_t> Sprite {};
};
    
} // namespace SalsaEngine
