#pragma once

namespace SalsaEngine {

struct GameContext_t {
    virtual const VecEntities_t& GetEntities() const = 0;       // 0 determines that this struct is abstract
};
    
} // namespace SalsaEngine
