#include <systems/Physics.hpp>
#include <utils/GameContext.hpp>
#include <utils/Debug.hpp>
/*----------------------------------------------------------------------------------------*/


namespace VVE {

    bool 
    PhysicsSystem_t::Update(GameContext_t& gameContext/*, const float deltaTime*/) const {
        
        for (auto& physicComp : gameContext.GetPhysicsComponents()) {
            physicComp.XPos += physicComp.velocityX;
            physicComp.YPos += physicComp.velocityY;
        }

        return true;
    }

} // namespace VVE