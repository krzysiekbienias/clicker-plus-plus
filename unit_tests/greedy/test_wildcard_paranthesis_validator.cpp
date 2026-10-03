#include "greedy/wildcard_paranthesis_validator.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(WildcardParanthesisValidatorTest, EmptyString) {
    EXPECT_TRUE(wildcard_parenthesis_validator(""));
}

TEST(WildcardParanthesisValidatorTest, SingleStar) {
    EXPECT_TRUE(wildcard_parenthesis_validator("*"));
}

TEST(WildcardParanthesisValidatorTest, TwoStars) {
    EXPECT_TRUE(wildcard_parenthesis_validator("**"));
}

TEST(WildcardParanthesisValidatorTest, SimplePair) {
    EXPECT_TRUE(wildcard_parenthesis_validator("()"));
}

TEST(WildcardParanthesisValidatorTest, StarAsEmpty) {
    EXPECT_TRUE(wildcard_parenthesis_validator("(*)"));
}

TEST(WildcardParanthesisValidatorTest, StarAsOpen) {
    EXPECT_TRUE(wildcard_parenthesis_validator("(*))"));
}

TEST(WildcardParanthesisValidatorTest, StarAsClose) {
    EXPECT_TRUE(wildcard_parenthesis_validator("(*"));
}

TEST(WildcardParanthesisValidatorTest, StarBeforeClose) {
    EXPECT_TRUE(wildcard_parenthesis_validator("*)"));
}

TEST(WildcardParanthesisValidatorTest, TrailingStar) {
    EXPECT_TRUE(wildcard_parenthesis_validator("()*"));
}

TEST(WildcardParanthesisValidatorTest, NestedWithStar) {
    EXPECT_TRUE(wildcard_parenthesis_validator("((*)"));
}

TEST(WildcardParanthesisValidatorTest, StarClosesEarlierOpen) {
    EXPECT_TRUE(wildcard_parenthesis_validator("(*()"));
}

TEST(WildcardParanthesisValidatorTest, BalancedWithoutStars) {
    EXPECT_TRUE(wildcard_parenthesis_validator("(())"));
}

TEST(WildcardParanthesisValidatorTest, StarBeforeOpenCannotCloseIt) {
    EXPECT_FALSE(wildcard_parenthesis_validator("*("));
}

TEST(WildcardParanthesisValidatorTest, StarsBeforeOpenCannotCloseIt) {
    EXPECT_FALSE(wildcard_parenthesis_validator("**("));
}

TEST(WildcardParanthesisValidatorTest, SingleOpen) {
    EXPECT_FALSE(wildcard_parenthesis_validator("("));
}

TEST(WildcardParanthesisValidatorTest, SingleClose) {
    EXPECT_FALSE(wildcard_parenthesis_validator(")"));
}

TEST(WildcardParanthesisValidatorTest, ReversedPair) {
    EXPECT_FALSE(wildcard_parenthesis_validator(")("));
}

TEST(WildcardParanthesisValidatorTest, CloseThenStarThenOpen) {
    EXPECT_FALSE(wildcard_parenthesis_validator(")*("));
}

TEST(WildcardParanthesisValidatorTest, LeadingClose) {
    EXPECT_FALSE(wildcard_parenthesis_validator(")*)"));
}

TEST(WildcardParanthesisValidatorTest, TwoOpensOneStar) {
    EXPECT_FALSE(wildcard_parenthesis_validator("((*"));
}

TEST(WildcardParanthesisValidatorTest, ExtraClose) {
    EXPECT_FALSE(wildcard_parenthesis_validator("())"));
}

TEST(WildcardParanthesisValidatorTest, ExtraOpen) {
    EXPECT_FALSE(wildcard_parenthesis_validator("(()"));
}

TEST(WildcardParanthesisValidatorTest, NotEnoughStarsToClose) {
    EXPECT_FALSE(wildcard_parenthesis_validator("(((*"));
}
