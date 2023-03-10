#include <algorithm>
#include <managers/EntityManager.hpp>
/*----------------------------------------------------------------------------------------*/

namespace SalsaEngine {

EntityManager_t::EntityManager_t() {
    _allEntities.reserve(kDEFAULT_INIT_ENTITIES);
}

void EntityManager_t::CreateEntity(uint32_t xPos, uint32_t yPos, std::string_view pngFile) {
    auto& createdEntity = _allEntities.emplace_back(pngFile);
    createdEntity.XPos = xPos;
    createdEntity.YPos = yPos;
    // std::fill(begin(createdEntity.Sprite), end(createdEntity.Sprite), color);
}
    
} // namespace SalsaEngine



