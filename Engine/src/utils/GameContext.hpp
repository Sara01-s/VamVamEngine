#pragma once

namespace SalsaEngine {

struct GameContext_t {
    virtual ~GameContext_t() = default;                         // Destructor marked as virtual because children have to implement their own destructor, this way the pointer who calls the destructor knows which object to delete
    virtual const VecEntities_t& GetEntities() const = 0;       // 0 determines that this struct is abstract
};

} // namespace SalsaEngine
