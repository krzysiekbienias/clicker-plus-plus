#include <gtest/gtest.h>

#include "recursion/phone_number_mnemonics.hpp"


TEST(PhoneNumbersDigits,TrivalCase)
{
    std::vector<std::string> expected = {
        "1w0j",
        "1w0k",
        "1w0l",
        "1x0j",
        "1x0k",
        "1x0l",
        "1y0j",
        "1y0k",
        "1y0l",
        "1z0j",
        "1z0k",
        "1z0l"};
    std::string input="1905";
    EXPECT_EQ(phoneNumberMnemonics(input),expected);
}

TEST(PhoneNumbersDigits, EmptyInputReturnsOneEmptyString)
{
    std::string input = "";
    std::vector<std::string> expected = {""}; // your backtrack pushes current at index==size
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, SingleDigitWithLetters_2)
{
    std::string input = "2";
    std::vector<std::string> expected = {"a","b","c"};
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, SingleDigitNoLetters_0)
{
    std::string input = "0";
    std::vector<std::string> expected = {"0"};
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, SingleDigitNoLetters_1)
{
    std::string input = "1";
    std::vector<std::string> expected = {"1"};
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, TwoDigits_23_AllCombinationsInOrder)
{
    std::string input = "23";
    std::vector<std::string> expected = {
        "ad","ae","af",
        "bd","be","bf",
        "cd","ce","cf"
    };
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, DigitsWith0And1_PreserveAsCharacters)
{
    std::string input = "101";
    std::vector<std::string> expected = {"101"};
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, RepeatedDigit_22)
{
    std::string input = "22";
    std::vector<std::string> expected = {
        "aa","ab","ac",
        "ba","bb","bc",
        "ca","cb","cc"
    };
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, TwoDigitsWith4Letters_79_OrderAndCount)
{
    std::string input = "79";
    std::vector<std::string> expected = {
        "pw","px","py","pz",
        "qw","qx","qy","qz",
        "rw","rx","ry","rz",
        "sw","sx","sy","sz"
    };
    EXPECT_EQ(phoneNumberMnemonics(input), expected);
}

TEST(PhoneNumbersDigits, SizeSanityCheck_BiggerInput)
{
    // "234" => 3 * 3 * 3 = 27 combinations
    std::string input = "234";
    auto res = phoneNumberMnemonics(input);
    EXPECT_EQ(res.size(), 27u);

    // quick spot-check first & last for order
    EXPECT_EQ(res.front(), "adg"); // a d g
    EXPECT_EQ(res.back(),  "cfi"); // c f i
}