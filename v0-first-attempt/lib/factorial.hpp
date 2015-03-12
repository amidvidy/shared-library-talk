#include <cstdint>
#include <iostream>
#include <unordered_map>

// MNMLSTC
#include <core/optional.hpp>

// The first attempt at writing libfactorial.

// This might be the way you would do it if this code was part of your
// application.

namespace factorial {

    using core::optional;

    class memoizer {
    public:
        void store(uint64_t input, uint64_t output);
        optional<uint64_t> get(uint64_t input);
    private:
        std::unordered_map<uint64_t, uint64_t> _data;
    };

    class calculator {
    public:
        calculator();

        // noncopyable
        calculator(const calculator&) = delete;
        calculator& operator=(const calculator&) = delete;

        // moveable
        calculator(calculator&&) = default;
        calculator& operator=(calculator&&) = default;

        uint64_t calculate(uint64_t input);
        inline uint64_t operator()(uint64_t input);
    private:
        memoizer _mem;
    };

    inline uint64_t calculator::operator()(uint64_t input) {
        return calculate(input);
    }

}
