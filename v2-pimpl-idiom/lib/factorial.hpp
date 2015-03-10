#include <cstdint>
// MNMLSTC
#include <core/optional.hpp>

#define FACTORIAL_API __attribute__ ((visibility ("default")))
#define FACTORIAL_PRIVATE __attribute__ ((visibility ("default")))

namespace factorial {

    // PIMPLed
    using core::optional;

    class FACTORIAL_API calculator {
    public:
        calculator();

        uint64_t calculate(uint64_t input);
        inline uint64_t operator()(uint64_t input);
    private:
        class FACTORIAL_PRIVATE impl;

        std::unique_ptr<impl> _impl;
    };

    inline uint64_t calculator::operator()(uint64_t input) {
        return calculate(input);
    }

}
