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
    for (const auto& entity : entities) {
        DrawSingleEntity(entity);
    }
}

void RenderSystem_t::DrawSingleEntity(const Entity_t& entity) const {
    auto screen { _frameBuffer.get() };                     // creates a "temporary copy of unique_ptr" inside this context by it's raw pointer

    auto getScreenXYPos = [&](const uint32_t xPos, const uint32_t yPos) {
        return screen + (yPos * _screenWidth) + xPos;
    };
    
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
}


// For bad apple video
int   _currentFrame = 0;
int   _frameRate    = 1000.0f / 24;
float _frameTimer   = 0.0f;

bool RenderSystem_t::Update(const GameContext_t& gameContext, float deltaTime) const {
    auto screen { _frameBuffer.get() };
    auto& entities = gameContext.GetEntities();


    // std::fill(screen, screen + _screenResolution, kK);     // Fill the screen with black
    // DrawAllEntities(gameContext.GetEntities());

    _frameTimer -= deltaTime;

    if (_frameTimer < 0) {
        _frameTimer += _frameRate;
        _currentFrame = (_currentFrame + 1) % entities.size();

        std::cout << "Drawing entity : " << entities[_currentFrame].Name << std::endl;
        DrawSingleEntity(entities[_currentFrame]);
    }

    ptc_update(screen);

    return !ptc_process_events();
}

} // namespace SalsaEngine
