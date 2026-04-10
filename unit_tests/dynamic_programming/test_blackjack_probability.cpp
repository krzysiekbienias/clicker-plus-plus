#include "dynamic_programming/blackjack_probability.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

const float EPSILON = 0.0001f;

TEST(BlackjackProbabilityTest, ExactProbabilityAtThresholdMinusOne) {
    // Target 21, Hand 16.
    // Karty 1-5 dają stand (0 porażki). Karty 6-10 dają bust (1 porażki).
    // Oczekiwany wynik: 5 * 0.1 = 0.5
    EXPECT_NEAR(blackjackProbability(21, 16), 0.5f, EPSILON);
}

TEST(BlackjackProbabilityTest, ExactProbabilityAtThresholdMinusTwo) {
    // Target 21, Hand 15.
    // Karty 2-6 dają stand (0). Karty 7-10 dają bust (0.4). Karta 1 daje 16 (0.1 * 0.5 = 0.05).
    // Oczekiwany wynik: 0.45
    EXPECT_NEAR(blackjackProbability(21, 15), 0.45f, EPSILON);
}

TEST(BlackjackProbabilityTest, ExactProbabilityAtThresholdMinusThree) {
    // Target 21, Hand 14.
    // Opiera się na obliczeniach dla 15 i 16.
    // Oczekiwany wynik: 0.3 + (0.1 * 0.45) + (0.1 * 0.5) = 0.395
    EXPECT_NEAR(blackjackProbability(21, 14), 0.395f, EPSILON);
}

TEST(BlackjackProbabilityTest, SmallTargetExactCalculation) {
    // Target 15, Hand 10.
    // Stand range: 11-15. Hand: 10.
    // Karty 1-5 dają stand. Karty 6-10 dają bust.
    // Oczekiwany wynik: 0.5
    EXPECT_NEAR(blackjackProbability(15, 10), 0.5f, EPSILON);
}