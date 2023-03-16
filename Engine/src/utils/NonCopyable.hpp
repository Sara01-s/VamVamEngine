#pragma once

namespace VamVam {

    struct NonCopyable {

        NonCopyable() = delete;
        NonCopyable(const NonCopyable& ) = delete;
        NonCopyable(NonCopyable&&)       = delete;
        NonCopyable& operator=(const NonCopyable& ) = delete;
        NonCopyable& operator=(NonCopyable&&)       = delete;

    };
    
} // namespace VamVam
