#include "numbers_theory/fizz_buzz.hpp"
#include <gtest/gtest.h>
#include <std_aliases.hpp>

using namespace stl;

TEST(FizzBuzz,Trival) {
    EXPECT_EQ(fizzBuzz(5),(vector<string>{"1","2","Fizz","4","Buzz"}));
}