#pragma once
#include <optional>
#include <cstdint>
#include <numeric> // std::gcd

namespace comb {

static constexpr uint64_t DEFAULT_CAP = 1'000'000ULL;

// Safe multiply with cap check: returns nullopt if a*b > cap
inline std::optional<uint64_t> mul_cap(uint64_t a, uint64_t b, uint64_t cap) {
    if (a == 0 || b == 0) return 0ULL;
    if (a > cap / b) return std::nullopt; // would exceed cap
    return a * b;
}

// Integer division (exact by construction in our loops)
inline uint64_t div_exact(uint64_t a, uint64_t b) {
    // precondition: b divides a
    return a / b;
}

// Exact nCk with early cap check; returns nullopt if result > cap.
inline std::optional<uint64_t> nCk_bounded(unsigned n, unsigned k, uint64_t cap = DEFAULT_CAP) {
    if (k > n) return 0ULL;
    if (k > n - k) k = n - k;

    uint64_t res = 1;
    for (unsigned i = 1; i <= k; ++i) {
        uint64_t num = n - k + i; // multiply by this
        uint64_t den = i;         // then divide by this

        // Reduce fraction num/den first to keep numbers small.
        uint64_t g1 = std::gcd(num, den);
        num /= g1; den /= g1;

        // Also reduce res/den if possible.
        uint64_t g2 = std::gcd(res, den);
        res /= g2; den /= g2;

        // Multiply by remaining numerator; check cap.
        auto t = mul_cap(res, num, cap);
        if (!t) return std::nullopt; // would exceed the cap
        res = *t;

        // Now exact division
        res = div_exact(res, den);

        // Optional: short-circuit if already above cap
        if (res > cap) return std::nullopt;
    }
    return res;
}

// Exact nPk = n*(n-1)*...*(n-k+1) with cap check.
inline std::optional<uint64_t> nPk_bounded(unsigned n, unsigned k, uint64_t cap = DEFAULT_CAP) {
    if (k > n) return 0ULL;
    uint64_t res = 1;
    for (unsigned i = 0; i < k; ++i) {
        auto t = mul_cap(res, (uint64_t)(n - i), cap);
        if (!t) return std::nullopt;
        res = *t;
        if (res > cap) return std::nullopt;
    }
    return res;
}

// Combinations with repetition: C(n + k - 1, k)
inline std::optional<uint64_t> nCk_rep_bounded(unsigned n, unsigned k, uint64_t cap = DEFAULT_CAP) {
    if (n == 0 && k > 0) return 0ULL; // by convention
    return nCk_bounded(n + k - 1, k, cap);
}

// Variations with repetition: n^k (cap-checked fast pow)
inline std::optional<uint64_t> pow_bounded(uint64_t base, unsigned exp, uint64_t cap = DEFAULT_CAP) {
    uint64_t res = 1;
    while (exp) {
        if (exp & 1u) {
            auto t = mul_cap(res, base, cap);
            if (!t) return std::nullopt;
            res = *t;
        }
        exp >>= 1u;
        if (exp) {
            auto t = mul_cap(base, base, cap);
            if (!t) return std::nullopt;
            base = *t;
        }
    }
    return res;
}

inline std::optional<uint64_t> nPk_rep_bounded(unsigned n, unsigned k, uint64_t cap = DEFAULT_CAP) {
    return pow_bounded(n, k, cap); // n^k
}




} // namespace comb