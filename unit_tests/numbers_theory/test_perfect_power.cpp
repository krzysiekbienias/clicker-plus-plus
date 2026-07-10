#include "numbers_theory/perfect_power.hpp"
#include <gtest/gtest.h>
#include <std_aliases.hpp>

using namespace stl;

TEST(PerfectPower, IsPerfectPower) {
    EXPECT_TRUE(isPower(4));    // 2^2
    EXPECT_TRUE(isPower(8));    // 2^3
    EXPECT_TRUE(isPower(9));    // 3^2
    EXPECT_TRUE(isPower(16));   // 2^4
    EXPECT_TRUE(isPower(25));   // 5^2
    EXPECT_TRUE(isPower(27));   // 3^3
    EXPECT_TRUE(isPower(32));   // 2^5
    EXPECT_TRUE(isPower(36));   // 6^2
    EXPECT_TRUE(isPower(64));   // 2^6 / 4^3 / 8^2
    EXPECT_TRUE(isPower(100));  // 10^2
    EXPECT_TRUE(isPower(243));  // 3^5
    EXPECT_TRUE(isPower(1024)); // 2^10
}

TEST(PerfectPower, IsNotPerfectPower) {
    EXPECT_FALSE(isPower(2));
    EXPECT_FALSE(isPower(3));
    EXPECT_FALSE(isPower(5));
    EXPECT_FALSE(isPower(6));   // 2 * 3
    EXPECT_FALSE(isPower(7));
    EXPECT_FALSE(isPower(10));  // 2 * 5
    EXPECT_FALSE(isPower(12));  // 2^2 * 3
    EXPECT_FALSE(isPower(14));  // 2 * 7
    EXPECT_FALSE(isPower(15));  // 3 * 5
    EXPECT_FALSE(isPower(18));  // 2 * 3^2
    EXPECT_FALSE(isPower(30));  // 2 * 3 * 5
}
