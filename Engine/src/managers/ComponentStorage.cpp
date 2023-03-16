#include <managers/ComponentStorage.hpp>

namespace VamVam {

    PhysicsComponent_t& ComponentStorage_t::CreatePhysicsComponent() {
        auto& physicComponent = _physicComponents.emplace_back();
        return physicComponent;
    }
    
} // namespace VamVam
