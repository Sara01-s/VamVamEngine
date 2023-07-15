#include <main.hpp>

#include <systems/Collisions.hpp>
#include <systems/Renderer.hpp>
#include <systems/Physics.hpp>

#include <managers/EntityManager.hpp>

#include <iostream> // lo puso matemágico
#include <filesystem>
#include <algorithm>
#include <chrono>
/*----------------------------------------------------------------------------------------*/

constexpr uint32_t kSCREEN_WIDTH      { 1'080 };
constexpr uint32_t kSCREEN_HEIGHT     { 720 };
constexpr uint32_t kSCREEN_RESOLUTION { kSCREEN_WIDTH * kSCREEN_HEIGHT };

int
main() {

    try {
        const VVE::RenderSystem_t renderSystem { "Mi motor grafico owo", kSCREEN_WIDTH, kSCREEN_HEIGHT };

        VVE::CollisionSystem_t collisionSystem { };
        VVE::PhysicsSystem_t physicsSystem     { };
        VVE::EntityManager_t entityManager     { };

        entityManager.CreateEntity(0, 0, "assets/slime.png");
        
        auto previousTime = std::chrono::high_resolution_clock::now();
        // auto deltaTime { 0.0f };

        // Game loop
        while(renderSystem.Update(entityManager/*, deltaTime)*/)) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            // deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - previousTime).count() * 1000.0f;
            previousTime = currentTime;

            physicsSystem.Update(entityManager/*, deltaTime*/);
            collisionSystem.Update(entityManager/*, deltaTime*/);

        }
    }
    catch (...) {
        std::cout << "Exception captured\n";
    }

    return 0;
}