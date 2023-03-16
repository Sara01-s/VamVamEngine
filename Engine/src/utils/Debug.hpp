#pragma once
#include <utils/NonCopyable.hpp>
#include <iostream>

namespace VamVam {

    struct Debug_t : public NonCopyable {
        
        // Make struct non-copyable
        Debug_t() = delete;
        Debug_t(const Debug_t&) = delete;
        Debug_t& operator=(const Debug_t&) = delete;

        static void Log(const std::string_view message) {
            std::cout << "Log: " << message << std::endl;
        }

        static void LogError(const std::string_view message) {
            std::cout << "Log Error: " << message << std::endl;
        }

        static void LogWarning(const std::string_view message) {
            std::cout << "Log Warning: " << message << std::endl;
        }

    };
    
} // namespace VamVam
