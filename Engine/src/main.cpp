#include <main.hpp>
#include <systems/Renderer.hpp>
#include <managers/EntityManager.hpp>
/*----------------------------------------------------------------------------------------*/

constexpr uint32_t kSCREEN_WIDTH      { 960U };
constexpr uint32_t kSCREEN_HEIGHT     { 760U };
constexpr uint32_t kSCREEN_RESOLUTION { kSCREEN_WIDTH * kSCREEN_HEIGHT };

int main(void) {
    try {
        SalsaEngine::EntityManager_t entityManager;
        entityManager.CreateEntity(20, 40);

        const SalsaEngine::RenderSystem_t renderSystem { "Mi primer motor owo", kSCREEN_WIDTH, kSCREEN_HEIGHT };

        while(renderSystem.Update(entityManager));
    }
    catch (...) {
        std::cout << "Exception captured\n";
    }

    return 0;
}