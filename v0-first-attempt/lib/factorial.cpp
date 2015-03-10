#include "factorial.hpp"

#include <utility>

namespace factorial {

    using core::nullopt_t;
    using core::make_optional;

    //==================== memoizer ====================//

    void memoizer::store(uint64_t input, uint64_t output) {
        _data[input] = output;
    }

    optional<uint64_t> memoizer::get(uint64_t input) {
        auto iter = _data.find(input);
        if (iter != _data.end()) {
            return make_optional(iter->second);
        }
        return {};
    }

    //==================== calculator ====================//

    calculator::calculator(options opts)
        : _opts(std::move(opts))
        , _mem{} {

        _mem.store(0, 1);
    }

    uint64_t calculator::calculate(uint64_t input) {
        auto stored_res = _mem.get(input);
        if (stored_res) return stored_res.value();

        auto calculated_res = input * calculate(input - 1);
        _mem.store(input, calculated_res);

        return calculated_res;
    }

}
