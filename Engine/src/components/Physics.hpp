#pragma once
#include <cstdint>
/*----------------------------------------------------------------------------------------*/


namespace VVE {

    struct PhysicsComponent_t {

        explicit PhysicsComponent_t() = default;

        uint32_t   XPos    { 0 },    YPos    { 0 };
        int32_t  velocityX { 1 },  velocityY { 1 };
    };
    
} // namespace VVE
