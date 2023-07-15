#pragma once
#include <vector>
#include <components/Physics.hpp>
/*----------------------------------------------------------------------------------------*/


namespace VVE {

    struct ComponentStorage_t {
        explicit ComponentStorage_t(std::size_t initialSize) {
            _physicComponents.reserve(initialSize);
        }

        ComponentStorage_t() = delete;
        ComponentStorage_t(const ComponentStorage_t& ) = delete;
        ComponentStorage_t(ComponentStorage_t&&)       = delete;                    // && = reference to an RValue (temp value or anonymous value)
        ComponentStorage_t& operator=(const ComponentStorage_t& ) = delete;
        ComponentStorage_t& operator=(ComponentStorage_t&&)       = delete;

        PhysicsComponent_t& CreatePhysicsComponent();
        
        const std::vector<PhysicsComponent_t>& GetPhysicsComponents() const { return _physicComponents; }
              std::vector<PhysicsComponent_t>& GetPhysicsComponents()       { return _physicComponents; }

    private:

        std::vector<PhysicsComponent_t> _physicComponents { };

    };
    
} // namespace VVE
