extern "C" { 
    #include <../libs/tinyPTC/src/tinyptc.h>
}
#include <algorithm>
#include <systems/Renderer.hpp>
#include <utils/TypeAliases.hpp>
#include <utils/GameContext.hpp>
#include <managers/EntityManager.hpp>
/*----------------------------------------------------------------------------------------*/


namespace SalsaEngine {
// RAII //
RenderSystem_t::RenderSystem_t(std::string_view gameTitle, uint32_t screenWidth, uint32_t screenHeight)
    : _screenWidth { screenWidth }, _screenHeight { screenHeight }, _screenResolution { _screenWidth * _screenHeight }
    , _frameBuffer { std::make_unique<uint32_t[]>(_screenResolution) }
{
    ptc_open(gameTitle.data(), screenWidth, screenHeight);
}

RenderSystem_t::~RenderSystem_t() { ptc_close(); }
// RAII //


// Render Game

void RenderSystem_t::DrawAllEntities(const VecEntities_t& entities) const {

    auto screen { _frameBuffer.get() };                     // creates a "temporary copy of unique_ptr" inside this context by it's raw pointer

    auto getScreenXYPos = [&](const uint32_t xPos, const uint32_t yPos) {
        return screen + (yPos * _screenWidth) + xPos;
    };
    
    auto DrawEntity = [&](const Entity_t& entity) {
        auto screenPos = getScreenXYPos(entity.XPos, entity.YPos);
        auto spriteItr = entity.Sprite.data();

        for (uint32_t entityY=0; entityY < entity.Height; ++entityY) {
            std::copy(
                spriteItr                                   // From the start of the sprite's row
                , spriteItr + entity.Width                  // To the end of the sprite's row
                , screenPos
            );

            spriteItr += entity.Width;                      // Jump to next row
            screenPos += _screenWidth;
        }
    };

    std::for_each(begin(entities), end(entities), DrawEntity);
}


bool RenderSystem_t::Update(const GameContext_t& gameContext) const {
    auto screen { _frameBuffer.get() };

    std::fill(screen, screen + _screenResolution, kK);     // Fill the screen with blue

    DrawAllEntities(gameContext.GetEntities());
    ptc_update(screen);

    return !ptc_process_events();
}

} // namespace SalsaEngine
