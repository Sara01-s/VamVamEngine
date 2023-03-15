#include <systems/Physics.hpp>
#include <utils/GameContext.hpp>

namespace VamVam {

    bool PhysicsSystem_t::Update(GameContext_t& gameContext, const float deltaTime) const {
        
        for (auto& entity : gameContext.GetEntities()) {
            entity.XPos += entity.velocityX;
            entity.YPos += entity.velocityY;
        }

        return true;
    }

} // namespace VamVam