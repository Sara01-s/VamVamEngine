#include <systems/Collisions.hpp>
#include <utils/GameContext.hpp>
#include <utils/Debug.hpp>
/*----------------------------------------------------------------------------------------*/

namespace VamVam {

    bool
    CollisionSystem_t::Update(GameContext_t& gameContext/*, const float deltaTime*/) const {

        for (auto& entity : gameContext.GetEntities()) {
            
            if (entity.Physics == nullptr) {
                Debug_t::LogWarning("Physic component is null!");
                return false;
            }

            if (entity.Physics-> XPos > 1080 || entity.Physics-> XPos + entity.Width > 1080) {
                entity.Physics-> XPos     -= static_cast<uint32_t>( entity.Physics-> velocityX);
                entity.Physics-> velocityX = static_cast<uint32_t>(-entity.Physics-> velocityX);
            }

            if (entity.Physics-> YPos > 720 || entity.Physics-> YPos + entity.Width > 720) {
                entity.Physics-> YPos     -= static_cast<uint32_t>( entity.Physics-> velocityY);
                entity.Physics-> velocityY = static_cast<uint32_t>(-entity.Physics-> velocityY);
            }
        }

        return true;
    }
    
} // namespace VamVam
