extern "C" {
    #include <../libs/miniaudio/src/miniaudio.h>
}

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
        SalsaEngine::EntityManager_t entityManager;
        fs::path dirPath("assets/Video3");

        std::vector<std::filesystem::path> filePaths;
        std::vector<fs::path> files;

        for (const auto& dirEntry : std::filesystem::directory_iterator(dirPath)) {
            if (std::filesystem::is_regular_file(dirEntry)) {
                filePaths.push_back(dirEntry.path());
            }
        }

        // Sort the file paths based on the numeric part of their filenames
        std::sort(filePaths.begin(), filePaths.end(), [](const auto& a, const auto& b) {
            auto filenameA = a.filename().string();
            auto filenameB = b.filename().string();
            auto startA = filenameA.find_first_of("0123456789");
            auto startB = filenameB.find_first_of("0123456789");

            if (startA == std::string::npos || startB == std::string::npos) {
                return filenameA < filenameB;
            }
            
            return std::stoi(filenameA.substr(startA)) < std::stoi(filenameB.substr(startB));
        });

        // Print the sorted file paths
        for (const auto& filePath : filePaths) {
            std::cout << "Creada entidad: " << filePath << '\n';
            entityManager.CreateEntity(0, 0, filePath.string());
        }
        ma_engine engine;

        ma_result result = ma_engine_init(nullptr, &engine);
        if (result != MA_SUCCESS) {
            printf("Failed to initialize miniaudio.\n");
            return -1;
        }
        
        ma_sound_group group;
        ma_sound_group_init(&engine, 1, NULL, &group);


        ma_engine_play_sound(&engine, "assets/lagartija.mp3", &group);

        const SalsaEngine::RenderSystem_t renderSystem { "Mi primer motor owo", kSCREEN_WIDTH, kSCREEN_HEIGHT };
        auto previousTime = std::chrono::high_resolution_clock::now();
        float deltaTime { 0.0f };

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