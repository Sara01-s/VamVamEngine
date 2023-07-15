#include <managers/ComponentStorage.hpp>

namespace VVE {

    PhysicsComponent_t&
    ComponentStorage_t::CreatePhysicsComponent() {

        auto& physicComponent = _physicComponents.emplace_back();

        return physicComponent;
    }
    
} // namespace VVE
