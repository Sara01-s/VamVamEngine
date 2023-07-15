#pragma once
#include <iostream>
#include <cstdint>
#include <memory>
#include <utils/TypeAliases.hpp>
/*----------------------------------------------------------------------------------------*/


namespace VVE {

    // tells the compiler that GameContext is a struct. No more details are necessary
    // because RenderSystem only stores a reference to GameContext_t. This is called forward declaration
    struct GameContext_t;

    struct RenderSystem_t {
        explicit RenderSystem_t(
            std::string_view gameTitle, 
            uint32_t screenWidth, uint32_t screenHeight
        );
        
        ~RenderSystem_t();

        bool Update(const GameContext_t& gameContext/*, const float deltaTime*/) const;

        void DrawSingleEntity(const Entity_t& entity) const;
        void DrawAllEntities(const VecEntities_t& entities) const;

        /// Color Constants
        static constexpr uint32_t kR = 0x00'FF'00'00;                      // Red   hex value
        static constexpr uint32_t kG = 0x00'00'FF'00;                      // Green hex value
        static constexpr uint32_t kB = 0x00'00'00'FF;                      // Blue  hex value
        static constexpr uint32_t kW = 0xFF'FF'FF'FF;                      // White hex value
        static constexpr uint32_t kK = 0x00'00'00'00;                      // Black hex value

    private:
        const uint32_t _screenWidth { 0 }, _screenHeight { 0 }, _screenResolution { 0 };
        std::unique_ptr<uint32_t[]> _frameBuffer { nullptr };
    };

} // namespace SalsaGameEngine

