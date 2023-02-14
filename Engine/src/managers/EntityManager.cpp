#include <algorithm>
#include <managers/EntityManager.hpp>
/*----------------------------------------------------------------------------------------*/

namespace SalsaEngine {

EntityManager_t::EntityManager_t() {
    _entities.reserve(kDEFAULT_INIT_ENTITIES);
}

void EntityManager_t::CreateEntity(uint32_t width, uint32_t height, uint32_t color) {
    auto& createdEntity = _entities.emplace_back(width, height);
    std::fill(begin(createdEntity.Sprite), end(createdEntity.Sprite), color);
}
    
} // namespace SalsaEngine



