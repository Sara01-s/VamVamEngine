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

struct Game_t {

public:
    Game_t(uint32_t screenWidth, uint32_t screenHeight)
        : _screen(new uint32_t[screenWidth * screenHeight]) {}

    Game_t(uint32_t screenResolution) 
        : _screen(new uint32_t[screenResolution]) {}

    ~Game_t() { delete[] _screen; }

    uint32_t* GetScreen() { return _screen; }

private:
    uint32_t* _screen { nullptr };
};


int main() {

    ptc_open("window", SCREEN_WIDTH, SCREEN_HEIGHT);

    Game_t game (SCREEN_RESOLUTION);

    while (!ptc_process_events()) {
        
        for (uint32_t pixel=0; pixel < SCREEN_RESOLUTION; ++pixel) {
            game.GetScreen()[pixel] = R;
        }

        uint32_t* screenPtr = game.GetScreen();
        const uint32_t* spritePtr = _sprite;

        for (uint32_t i=0; i < 8; ++i) {
            for (uint32_t j=0; j < 8; ++j) {

                *screenPtr = *spritePtr;

                ++screenPtr;
                ++spritePtr;
            }

            spritePtr += SCREEN_WIDTH - 8;
        }

        ptc_update(game.GetScreen());
    }

        


    ptc_close();

    return 0;
}