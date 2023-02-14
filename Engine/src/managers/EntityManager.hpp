#pragma once
#include <cstdint>
#include <vector>
/*----------------------------------------------------------------------------------------*/

namespace SalsaEngine {

struct Entity_t {

    explicit Entity_t(uint32_t width, uint32_t height) 
        : Width { width }, Height { height }
    {
        Sprite.resize(Width * Height);              // Vector's capacity now is sprite's resolution
    }

    uint32_t X { 0 }, Y { 0 };
    uint32_t Width { 0 }, Height { 0 };

    std::vector<uint32_t> Sprite {};
};

struct EntityManager_t {
    using VecEntities_t = std::vector<Entity_t>;
    
    explicit EntityManager_t();

    static constexpr inline std::size_t kDEFAULT_INIT_ENTITIES { 100 };


    void CreateEntity(uint32_t width, uint32_t height, uint32_t color);
    const VecEntities_t& GetEntities() const { return _entities; }


private:

    VecEntities_t _entities {};

};

}; // namespace SalsaEngine

