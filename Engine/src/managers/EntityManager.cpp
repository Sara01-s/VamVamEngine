#include <algorithm>
#include <components/Physics.hpp>
#include <managers/EntityManager.hpp>
/*----------------------------------------------------------------------------------------*/

namespace VamVam {

    EntityManager_t::EntityManager_t() {
        _allEntities.reserve(kDEFAULT_INIT_ENTITIES);
    }

    void
    EntityManager_t::CreateEntity(uint32_t xPos, uint32_t yPos, std::string_view pngFile) {
        Entity_t entity { pngFile };
        std::cout << "Sigo existiendo aqui" << '\n';
        auto& createdEntity = _allEntities.emplace_back(entity); // SUS
        auto& physicComponent = _componentStorage.CreatePhysicsComponent();

        createdEntity.Physics = &physicComponent;

        physicComponent.XPos = xPos;
        physicComponent.YPos = yPos;
    }
    
} // namespace VamVam



