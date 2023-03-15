#pragma once
#include <iostream>
#include <cstdint>
#include <utils/TypeAliases.hpp>
/*----------------------------------------------------------------------------------------*/


namespace VamVam {

// tells the compiler that GameContext is a struct. No more details are necessary
// because RenderSystem only stores a reference to GameContext_t. This is called forward declaration
struct GameContext_t;

struct PhysicsSystem_t {
    explicit PhysicsSystem_t() = default;

    bool Update(const GameContext_t& gameContext, float deltaTime) const;
};

} // namespace SalsaGameEngine

