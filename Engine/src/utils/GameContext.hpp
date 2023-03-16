#pragma once

namespace VamVam {

    struct GameContext_t {
        virtual ~GameContext_t() = default;                         // Destructor marked as virtual because children have to implement their own destructor, this way the pointer who calls the destructor knows which object to delete
        virtual const VecEntities_t& GetEntities() const = 0;       // 0 determines that any child of this struct is abstract until they implement all the methods.
        virtual       VecEntities_t& GetEntities()       = 0;       // non-const variant of GetEntities

        virtual const std::vector<PhysicsComponent_t>& GetPhysicsComponents() const = 0;
        virtual       std::vector<PhysicsComponent_t>& GetPhysicsComponents()       = 0;
    };

} // namespace VamVam
