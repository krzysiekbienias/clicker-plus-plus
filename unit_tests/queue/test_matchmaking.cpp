#include "queue/matchmaking.hpp"
#include <gtest/gtest.h>

#include <queue>
#include <string>
#include <initializer_list>

using std::string;

static std::queue<User> makeQueue(std::initializer_list<User> users) {
    std::queue<User> q;
    for (const auto& u : users) {
        q.push(u);
    }
    return q;
}

// Po join/leave: przy < 4 osobach w kolejce nie ma meczu.
// Przy >= 4: zdejmij dwie pierwsze osoby (FIFO) i zwroc "m1 matched m2".

TEST(Matchmake, EmptyQueueJoinOne_NoMatch) {
    auto q = makeQueue({});
    EXPECT_EQ(matchmake(q, {"Alice", "join"}), "No match found");
}

TEST(Matchmake, TwoInQueueJoinThird_NoMatch) {
    auto q = makeQueue({{"Alice", "join"}, {"Bob", "join"}});
    EXPECT_EQ(matchmake(q, {"Carol", "join"}), "No match found");
}

TEST(Matchmake, ThreeInQueueJoinFourth_MatchesFirstTwo) {
    auto q = makeQueue({{"Alice", "join"}, {"Bob", "join"}, {"Carol", "join"}});
    EXPECT_EQ(matchmake(q, {"Dave", "join"}), "Alice matched Bob");
}

TEST(Matchmake, FourWaitingJoinFifth_MatchesFirstTwo) {
    auto q = makeQueue({
        {"Alice", "join"},
        {"Bob", "join"},
        {"Carol", "join"},
        {"Dave", "join"}});
    EXPECT_EQ(matchmake(q, {"Eve", "join"}), "Alice matched Bob");
}

TEST(Matchmake, LeaveFrontWhenFour_NoMatch) {
    auto q = makeQueue({
        {"Alice", "join"},
        {"Bob", "join"},
        {"Carol", "join"},
        {"Dave", "join"}});
    EXPECT_EQ(matchmake(q, {"Alice", "leave"}), "No match found");
}

TEST(Matchmake, LeaveWhenFewerThanFour_NoMatch) {
    auto q = makeQueue({{"Alice", "join"}, {"Bob", "join"}});
    EXPECT_EQ(matchmake(q, {"Alice", "leave"}), "No match found");
}

TEST(Matchmake, LeaveMissingName_DoesNotChangeQueue) {
    auto q = makeQueue({{"Alice", "join"}, {"Bob", "join"}});
    EXPECT_EQ(matchmake(q, {"Zoe", "leave"}), "No match found");
}

TEST(Matchmake, LeaveMiddleThenStillFour_MatchesRemainingPair) {
    auto q = makeQueue({
        {"Alice", "join"},
        {"Bob", "join"},
        {"Carol", "join"},
        {"Dave", "join"},
        {"Eve", "join"}});
    // po usunieciu Carol: Alice, Bob, Dave, Eve -> "Alice matched Bob"
    EXPECT_EQ(matchmake(q, {"Carol", "leave"}), "Alice matched Bob");
}

TEST(Matchmake, EmptyQueueLeave_NoMatch) {
    auto q = makeQueue({});
    EXPECT_EQ(matchmake(q, {"Alice", "leave"}), "No match found");
}
