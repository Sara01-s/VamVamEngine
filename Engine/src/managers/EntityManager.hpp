#pragma once
#include <cstdint>
#include <vector>
#include <utils/TypeAliases.hpp>
#include <utils/GameContext.hpp>
#include <managers/ComponentStorage.hpp>
/*----------------------------------------------------------------------------------------*/

namespace VVE {

    struct EntityManager_t : public GameContext_t {

        explicit EntityManager_t();

        static constexpr inline std::size_t kDEFAULT_INIT_ENTITIES { 1'000 };

        void CreateEntity(uint32_t xPos, uint32_t yPos, std::string_view pngFile);

        const VecEntities_t& GetEntities() const override { return _allEntities; }
              VecEntities_t& GetEntities() override       { return _allEntities; }

        const std::vector<PhysicsComponent_t>& GetPhysicsComponents() const override { return _componentStorage.GetPhysicsComponents(); }
              std::vector<PhysicsComponent_t>& GetPhysicsComponents()       override { return _componentStorage.GetPhysicsComponents(); }


    private:

        VecEntities_t _allEntities { };
        ComponentStorage_t _componentStorage { kDEFAULT_INIT_ENTITIES };

    };

}; // namespace VVE

