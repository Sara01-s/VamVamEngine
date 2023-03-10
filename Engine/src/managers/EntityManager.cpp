#include <algorithm>
#include <managers/EntityManager.hpp>
/*----------------------------------------------------------------------------------------*/

namespace SalsaEngine {

EntityManager_t::EntityManager_t() {
    _allEntities.reserve(kDEFAULT_INIT_ENTITIES);
}

void EntityManager_t::CreateEntity(uint32_t xPos, uint32_t yPos) {
    auto& createdEntity = _allEntities.emplace_back("assets/BadAppleFrame_6485.png");
    createdEntity.XPos = xPos;
    createdEntity.YPos = yPos;
    // std::fill(begin(createdEntity.Sprite), end(createdEntity.Sprite), color);
}
    
} // namespace SalsaEngine



