#include <cstdint>
// MNMLSTC
#include <core/optional.hpp>

#define FACTORIAL_API [[gnu::visibility("default")]]
#define FACTORIAL_PRIVATE [[gnu::visibility("hidden")]]
// we need to insure that compilers *never* include inline functions in the ABI
// compilers use heuristics to determine what functions declared inline to actually inline.
// always_inline forces clang/gcc to inline if possible.
#define FACTORIAL_INLINE [[gnu::always_inline]] inline

// we want the inline namespace to have the ABI version. This is a super ugly way of doing
// it, in reality CMake or SCons would make this way nicer.
#define FACTORIAL_ABI_VERSION 0
// really you would have the build system interpolate the namespace name with the version number
// but I'm not using a build system, so here are some ugly macro hacks.
#define _C(A,B) A##B
#define C(A,B) _C(A,B)
#define FACTORIAL_INLINE_NAMESPACE_BEGIN inline namespace C(v,FACTORIAL_ABI_VERSION) {
#define FACTORIAL_INLINE_NAMESPACE_END }

namespace factorial {
FACTORIAL_INLINE_NAMESPACE_BEGIN

    class FACTORIAL_API calculator {
    public:
        calculator();
        ~calculator();

        // noncopyable
        calculator(const calculator&) = delete;
        calculator& operator=(const calculator&) = delete;

        calculator(calculator&&) noexcept;
        calculator& operator=(calculator&&) noexcept;

        uint64_t calculate(uint64_t input);
        FACTORIAL_INLINE uint64_t operator()(uint64_t input);
    private:
        class FACTORIAL_PRIVATE impl;
        std::unique_ptr<impl> _impl;
    };

    FACTORIAL_INLINE uint64_t calculator::operator()(uint64_t input) {
        return calculate(input);
    }

FACTORIAL_INLINE_NAMESPACE_END
}  // namespace factorial
