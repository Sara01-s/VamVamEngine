#pragma once
#include <cstdint>
#include <vector>
/*----------------------------------------------------------------------------------------*/


namespace SalsaEngine {

struct Entity_t {

    explicit Entity_t(uint32_t width, uint32_t height) 
        : Width { width }, Height { height }
    {
        Sprite.resize(Width * Height);              // Vector's capacity now is sprite's resolution
    }

    uint32_t XPos { 0 }, YPos { 0 };
    uint32_t Width { 0 }, Height { 0 };

    std::vector<uint32_t> Sprite {};
};
    
} // namespace SalsaEngine
