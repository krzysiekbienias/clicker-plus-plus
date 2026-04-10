#include "bit_manipulation/minimize_xor.hpp"
#include <gtest/gtest.h>


// Case 1: num1 and num2 have the same number of set bits.
// Result should be exactly num1 (XOR result = 0).
TEST(MinimizeXorTest, SameSetBitCount) {
    int num1 = 3; // binary: 011 (2 bits)
    int num2 = 5; // binary: 101 (2 bits)
    // x should be 3 to minimize XOR.
    EXPECT_EQ(minimizeXor(num1, num2), 3);
}

// Case 2: num2 has fewer set bits than num1.
// We should pick the most significant bits of num1.
TEST(MinimizeXorTest, FewerSetBitsInNum2) {
    int num1 = 25; // binary: 11001 (3 bits)
    int num2 = 72; // binary: 1001000 (2 bits)
    // Budget is 2 bits. Highest bits of 25 are 16 and 8.
    // Expected x: 11000 (24)
    EXPECT_EQ(minimizeXor(num1, num2), 24);
}

// Case 3: num2 has more set bits than num1.
// We take all bits from num1 and fill the remaining from the lowest available positions.
TEST(MinimizeXorTest, MoreSetBitsInNum2) {
    int num1 = 1;  // binary: 0001 (1 bit)
    int num2 = 15; // binary: 1111 (4 bits)
    // Budget is 4 bits. Take the bit at index 0, then fill indices 1, 2, 3.
    // Expected x: 1111 (15)
    EXPECT_EQ(minimizeXor(num1, num2), 15);
}

// Case 4: num1 is zero.
// Result should be a number with nbOfSetBits2Budget starting from the right.
TEST(MinimizeXorTest, Num1IsZero) {
    int num1 = 0;
    int num2 = 3; // binary: 011 (2 bits)
    // x should be 3 (binary: 11)
    EXPECT_EQ(minimizeXor(num1, num2), 3);
}

// Case 5: Large values and bit boundary check.
TEST(MinimizeXorTest, LargeValues) {
    int num1 = 8;          // binary: 1000
    int num2 = 1073741823; // 30 bits set
    // x should have 30 bits set, including the bit from num1.
    int result = minimizeXor(num1, num2);
    // Count bits of result to ensure budget was met
    EXPECT_EQ(__builtin_popcount(result), __builtin_popcount(num2));
}