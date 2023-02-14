#include <main.hpp>
#include <systems/Renderer.hpp>
#include <managers/EntityManager.hpp>
/*----------------------------------------------------------------------------------------*/

constexpr uint32_t kSCREEN_WIDTH      { 640U };
constexpr uint32_t kSCREEN_HEIGHT     { 360U };
constexpr uint32_t kSCREEN_RESOLUTION { kSCREEN_WIDTH * kSCREEN_HEIGHT };

int main(void) {
    try {
        SalsaEngine::EntityManager_t entityManager {};
        entityManager.CreateEntity(160, 160, 0x0000FF00U);
        const SalsaEngine::RenderSystem_t renderSystem { "Mi primer motor owo", 640U, 360U, entityManager };

        while(renderSystem.Update());
    }
    catch (...) {
        std::cout << "Exception captured\n";
    }

    return 0;
}