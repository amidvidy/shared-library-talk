#include <cstdint>
#include <iostream>
#include <unordered_map>

// MNMLSTC
#include <core/optional.hpp>

// The first attempt at writing libfactorial.

// This might be the way you would do it if this code was part of your
// application.

#define FACTORIAL_API __attribute__ ((visibility ("default")))
#define FACTORIAL_PRIVATE __attribute__ ((visibility ("default")))

namespace factorial {

    using core::optional;

    struct FACTORIAL_API options {
        options() = default;
        options(options&&) = default;

        bool memoize{true};
    };

    class memoizer {
    public:
        void store(uint64_t input, uint64_t output);
        optional<uint64_t> get(uint64_t input);
    private:
        std::unordered_map<uint64_t, uint64_t> _data;
    };

    class FACTORIAL_API calculator {
    public:
        calculator(options opts);
        uint64_t calculate(uint64_t input);
        inline uint64_t operator()(uint64_t input);
    private:
        options _opts;
        memoizer _mem;
    };

    inline uint64_t calculator::operator()(uint64_t input) {
        return calculate(input);
    }

}
