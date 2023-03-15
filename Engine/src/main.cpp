#include <main.hpp>
#include <systems/Renderer.hpp>
#include <managers/EntityManager.hpp>
#include <filesystem>
#include <algorithm>
#include <chrono>
/*----------------------------------------------------------------------------------------*/

constexpr uint32_t kSCREEN_WIDTH      { 480U };
constexpr uint32_t kSCREEN_HEIGHT     { 360U };
constexpr uint32_t kSCREEN_RESOLUTION { kSCREEN_WIDTH * kSCREEN_HEIGHT };

namespace fs = std::filesystem;

int main(void) {
    try {

        const VamVam::EntityManager_t entityManager;
        const VamVam::PhysicsSystem_t renderSystem { "Mi primer motor owo", kSCREEN_WIDTH, kSCREEN_HEIGHT };

        auto previousTime = std::chrono::high_resolution_clock::now();
        auto deltaTime { 0.0f };

        // Game loop
        while(renderSystem.Update(entityManager, deltaTime)) {
            auto currentTime = std::chrono::high_resolution_clock::now();

            deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - previousTime).count() * 1000.0f;

            previousTime = currentTime;
        }
    }
    catch (...) {
        std::cout << "Exception captured\n";
    }

    return 0;
}