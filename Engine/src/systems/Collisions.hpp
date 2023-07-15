#pragma once
#include <utils/TypeAliases.hpp>
/*----------------------------------------------------------------------------------------*/


namespace VVE {

    struct GameContext_t;

    struct CollisionSystem_t {

        explicit CollisionSystem_t() = default;

        bool Update(GameContext_t& gameContext/*, const float deltaTime*/) const;

    };
    
} // namespace VVE
