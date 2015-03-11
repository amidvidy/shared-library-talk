#include "factorial.hpp"

#include <core/memory.hpp>

#include <unordered_map>
#include <utility>

namespace factorial {

    using ::core::make_optional;
    using ::core::make_unique;
    using ::core::nullopt_t;
    using ::core::optional;

    namespace {

        class memoizer {
        public:
            void store(uint64_t input, uint64_t output) {
                _data[input] = output;
            }
            optional<uint64_t> get(uint64_t input) {
                auto iter = _data.find(input);
                if (iter != _data.end()) {
                    return make_optional(iter->second);
                }
                return {};
            }
        private:
            std::unordered_map<uint64_t, uint64_t> _data;
        };

    }  // namespace

    class calculator::impl {
    public:
        impl()
            : _mem{} {
            _mem.store(0, 1);
        }

        uint64_t calculate(uint64_t input) {
            auto stored_res = _mem.get(input);
            if (stored_res) return stored_res.value();

            auto calculated_res = input * calculate(input - 1);
            _mem.store(input, calculated_res);

            return calculated_res;
        }

    private:
        memoizer _mem;
    };

    calculator::calculator()
        : _impl{core::make_unique<impl>()}
    {}

    // see header for why this is needed.
    calculator::~calculator() = default;

    calculator::calculator(calculator&&) noexcept = default;
    calculator& calculator::operator=(calculator&&) noexcept = default;

    uint64_t calculator::calculate(uint64_t input) {
        return _impl->calculate(input);
    }

}
