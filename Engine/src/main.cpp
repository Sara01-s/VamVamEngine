extern "C" { 
#include <../libs/tinyPTC/src/linux/tinyptc.h>
}

#include <cstdint>
#include "main.hpp"

constexpr uint32_t R = 0x00FF0000;                      // red   hex
constexpr uint32_t G = 0x0000FF00;                      // green hex
constexpr uint32_t B = 0x000000FF;                      // blue  hex
constexpr uint32_t SCREEN_WIDTH      { 640 };
constexpr uint32_t SCREEN_HEIGHT     { 360 };
constexpr uint32_t SCREEN_RESOLUTION { SCREEN_WIDTH * SCREEN_HEIGHT };


constexpr uint32_t _sprite[8*8] = {
    G, G, G, G, G, G, G, G,
    G, B, R, R, R, R, B, G,
    G, B, R, G, G, G, B, G,
    G, B, B, R, G, G, B, G,
    G, B, B, B, R, R, B, G,
    G, B, B, B, B, R, B, G,
    G, B, R, R, R, G, B, G,
    G, G, G, G, G, G, G, G
};

uint32_t* _gameScreen { nullptr };

int main() {

    ptc_open("window", SCREEN_WIDTH, SCREEN_HEIGHT);

    _gameScreen = new uint32_t[SCREEN_RESOLUTION];

    while (!ptc_process_events()) {
        
        for (uint32_t pixel=0; pixel < SCREEN_RESOLUTION; ++pixel) {
            _gameScreen[pixel] = R;
        }

        uint32_t* screenPtr = _gameScreen;
        const uint32_t* spritePtr = _sprite;

        for (uint32_t i=0; i < 8; ++i) {
            for (uint32_t j=0; j < 8; ++j) {

                *screenPtr = *spritePtr;

                ++screenPtr;
                ++spritePtr;
            }

            spritePtr += SCREEN_WIDTH - 8;
        }

        ptc_update(_gameScreen);
    }

        


    ptc_close();

    delete[] _gameScreen;

    return 0;
}