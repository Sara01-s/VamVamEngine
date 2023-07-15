#pragma once

namespace VVE {

    struct NonCopyable {

        NonCopyable() = delete;
        NonCopyable(const NonCopyable& ) = delete;
        NonCopyable(NonCopyable&&)       = delete;
        NonCopyable& operator=(const NonCopyable& ) = delete;
        NonCopyable& operator=(NonCopyable&&)       = delete;

    };
    
} // namespace VVE
