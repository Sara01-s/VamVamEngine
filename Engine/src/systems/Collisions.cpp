#include <systems/Collisions.hpp>
#include <utils/GameContext.hpp>
/*----------------------------------------------------------------------------------------*/

namespace VamVam {

    bool CollisionSystem_t::Update(GameContext_t& gameContext, const float deltaTime) const {

        for (auto& entity : gameContext.GetEntities()) {
            if (entity.XPos > 1080 || entity.XPos + entity.Width > 1080) {
                entity.XPos -= entity.velocityX;
                entity.velocityX = -entity.velocityX;
            }

            if (entity.YPos > 720 || entity.YPos + entity.Width > 720) {
                entity.YPos -= entity.velocityY;
                entity.velocityY = -entity.velocityY;
            }
        }

        return true;
    }
    
} // namespace VamVam
