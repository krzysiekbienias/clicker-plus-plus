#include "strings/intiger_to_roman.hpp"
#include <gtest/gtest.h>


// -------- Tests --------

TEST(IntToRoman, BasicSingles) {
    EXPECT_EQ(intToRoman(1), "I");
    EXPECT_EQ(intToRoman(5), "V");
    EXPECT_EQ(intToRoman(10), "X");
    EXPECT_EQ(intToRoman(50), "L");
    EXPECT_EQ(intToRoman(100), "C");
    EXPECT_EQ(intToRoman(500), "D");
    EXPECT_EQ(intToRoman(1000), "M");
}

TEST(IntToRoman, SubtractiveCases) {
    EXPECT_EQ(intToRoman(4), "IV");
    EXPECT_EQ(intToRoman(9), "IX");
    EXPECT_EQ(intToRoman(40), "XL");
    EXPECT_EQ(intToRoman(90), "XC");
    EXPECT_EQ(intToRoman(400), "CD");
    EXPECT_EQ(intToRoman(900), "CM");
}

TEST(IntToRoman, SmallNumbers_Mix) {
    std::vector<std::pair<int, std::string>> cases = {
        {2, "II"},
        {3, "III"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {11, "XI"},
        {14, "XIV"},
        {15, "XV"},
        {16, "XVI"},
        {19, "XIX"},
        {20, "XX"},
        {24, "XXIV"},
        {29, "XXIX"},
        {34, "XXXIV"},
        {39, "XXXIX"}
    };
    for (auto& [n, roman] : cases) {
        EXPECT_EQ(intToRoman(n), roman) << "n=" << n;
    }
}

TEST(IntToRoman, MediumNumbers_Mix) {
    std::vector<std::pair<int, std::string>> cases = {
        {44, "XLIV"},
        {49, "XLIX"},
        {58, "LVIII"},
        {68, "LXVIII"},
        {93, "XCIII"},
        {99, "XCIX"},
        {141, "CXLI"},
        {149, "CXLIX"},
        {166, "CLXVI"},
        {199, "CXCIX"},
        {242, "CCXLII"},
        {399, "CCCXCIX"},
        {444, "CDXLIV"},
        {499, "CDXCIX"},
        {707, "DCCVII"},
        {944, "CMXLIV"},
        {999, "CMXCIX"}
    };
    for (auto& [n, roman] : cases) {
        EXPECT_EQ(intToRoman(n), roman) << "n=" << n;
    }
}

TEST(IntToRoman, ThousandsAndUpperRange) {
    std::vector<std::pair<int, std::string>> cases = {
        {1001, "MI"},
        {1010, "MX"},
        {1024, "MXXIV"},
        {1066, "MLXVI"},
        {1776, "MDCCLXXVI"},
        {1984, "MCMLXXXIV"},
        {2014, "MMXIV"},
        {2421, "MMCDXXI"},
        {2999, "MMCMXCIX"},
        {3000, "MMM"},
        {3444, "MMMCDXLIV"},
        {3888, "MMMDCCCLXXXVIII"},
        {3999, "MMMCMXCIX"}
    };
    for (auto& [n, roman] : cases) {
        EXPECT_EQ(intToRoman(n), roman) << "n=" << n;
    }
}