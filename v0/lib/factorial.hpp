#include <cstdint>
#include <unordered_map>
#include <experimental/optional>

// The first attempt at writing libfactorial.

// This might be the way you would do it if this code was part of your
// application.

namespace factorial {

    struct options {
        bool memoize;
    };

    class memoizer {
    public:
        void store(uint64_t input, uint64_t output);
        std::experimental::optional<uint64_t> get(uint64_t input);
    private:
        std::unordered_map<uint64_t, uint64_t> _data;
    };

    class factorial {
    public:
        uint64_t calculate(uint64_t input);
    private:
        options _opts;
        memoizer _mem;
    };

}
