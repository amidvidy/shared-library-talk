#include <cstdint>
#include <iostream>
#include <unordered_map>

// MNMLSTC
#include <core/optional.hpp>

// Adding visibility annotations and compiling with -fvisibility=hidden

#define FACTORIAL_API __attribute__ ((visibility ("default")))
#define FACTORIAL_PRIVATE __attribute__ ((visibility ("default")))

namespace factorial {

    using core::optional;

    class memoizer {
    public:
        void store(uint64_t input, uint64_t output);
        optional<uint64_t> get(uint64_t input);
    private:
        std::unordered_map<uint64_t, uint64_t> _data;
    };

    class FACTORIAL_API calculator {
    public:
        calculator();

        calculator(const calculator&) = delete;
        calculator& operator=(const calculator&) = delete;

        calculator(calculator&&) noexcept = default;
        calculator& operator=(calculator&&) noexcept = default;

        uint64_t calculate(uint64_t input);
        inline uint64_t operator()(uint64_t input);
    private:
        memoizer _mem;
    };

    inline uint64_t calculator::operator()(uint64_t input) {
        return calculate(input);
    }

}  // namespace factorial
