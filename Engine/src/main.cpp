#include <main.hpp>

#include <systems/Collisions.hpp>
#include <systems/Renderer.hpp>
#include <systems/Physics.hpp>

#include <managers/EntityManager.hpp>

#include <filesystem>
#include <algorithm>
#include <chrono>
/*----------------------------------------------------------------------------------------*/

constexpr uint32_t kSCREEN_WIDTH      { 1080U };
constexpr uint32_t kSCREEN_HEIGHT     { 720U };
constexpr uint32_t kSCREEN_RESOLUTION { kSCREEN_WIDTH * kSCREEN_HEIGHT };

int main(void) {
    try {
        const VamVam::RenderSystem_t renderSystem { "Mi motor grafico owo", kSCREEN_WIDTH, kSCREEN_HEIGHT };

        VamVam::CollisionSystem_t collisionSystem;
        VamVam::PhysicsSystem_t physicsSystem;
        VamVam::EntityManager_t entityManager;

        entityManager.CreateEntity(0, 0, "assets/slime.png");

        auto previousTime = std::chrono::high_resolution_clock::now();
        auto deltaTime { 0.0f };

        // Game loop
        while(renderSystem.Update(entityManager, deltaTime)) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - previousTime).count() * 1000.0f;
            previousTime = currentTime;

            physicsSystem.Update(entityManager, deltaTime);
            collisionSystem.Update(entityManager, deltaTime);

        }
    }
    catch (...) {
        std::cout << "Exception captured\n";
    }

    return 0;
}