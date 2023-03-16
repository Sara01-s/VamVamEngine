#include <systems/Physics.hpp>
#include <utils/GameContext.hpp>
#include <utils/Debug.hpp>
/*----------------------------------------------------------------------------------------*/


namespace VamVam {

    bool 
    PhysicsSystem_t::Update(GameContext_t& gameContext, const float deltaTime) const {
        
        for (auto& physicComp : gameContext.GetPhysicsComponents()) {
            physicComp.XPos += physicComp.velocityX;
            physicComp.YPos += physicComp.velocityY;
        }

        return true;
    }

} // namespace VamVam