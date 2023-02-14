extern "C" { 
    #include <../libs/tinyPTC/src/tinyptc.h>
}

#include <memory>
#include <cstdint>
#include <iostream>
#include <exception>
#include "main.hpp"
/*----------------------------------------------------------------------------------------*/


constexpr uint32_t kR = 0x00FF0000U;                      // red   hex
constexpr uint32_t kG = 0x0000FF00U;                      // green hex
constexpr uint32_t kB = 0x000000FFU;                      // blue  hex
constexpr uint32_t kW = 0xFFFFFFFFU;                      // white hex
constexpr uint32_t kSCREEN_WIDTH      { 640U };
constexpr uint32_t kSCREEN_HEIGHT     { 360U };
constexpr uint32_t kSCREEN_RESOLUTION { kSCREEN_WIDTH * kSCREEN_HEIGHT };


constexpr const uint32_t _sprite[8*8] = {
    kG, kG, kG, kG, kG, kG, kG, kG,
    kG, kB, kR, kR, kR, kB, kB, kG,
    kG, kB, kR, kW, kW, kR, kB, kG,
    kG, kB, kR, kR, kR, kR, kB, kG,
    kG, kB, kR, kR, kR, kR, kB, kG,
    kG, kB, kR, kR, kR, kR, kB, kG,
    kG, kB, kR, kB, kB, kR, kB, kG,
    kG, kG, kG, kG, kG, kG, kG, kG
};
/*----------------------------------------------------------------------------------------*/

void ExecuteGame(const std::string_view gameTitle) {

    ptc_open(gameTitle.data(), kSCREEN_WIDTH, kSCREEN_HEIGHT);

    auto screen { std::make_unique<uint32_t[]>(kSCREEN_RESOLUTION) };

    while (!ptc_process_events()) {
        
        for (uint32_t pixel=0; pixel < kSCREEN_RESOLUTION; ++pixel) {
            screen[pixel] = kB;
        }
        
        uint32_t* screenPtr = screen.get();
        const uint32_t* spritePtr = _sprite;

        for (uint32_t i{}; i < 8; ++i) {
            for (uint32_t j{}; j < 8; ++j) {

                *screenPtr = *spritePtr;

                ++screenPtr;
                ++spritePtr;
            }

            screenPtr += kSCREEN_WIDTH - 8;
        }
        
        ptc_update(screen.get());
    }

    ptc_close();
}

int main() {
    try {
        ExecuteGame("Mi primer motor grafico owo");
    }
    catch (...) {
        std::cout << "Exception captured\n";
    }

    return 0;
}