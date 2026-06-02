#include "simulations/robot_and_obstacles.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(RobotSimulation,BaseCase)
{
    std::vector <int> commands={4,-1,4,-2,4};
    std::vector <std::vector<int>> obstacles{{2,4}};

    int actual =robotSim(commands,obstacles);
    EXPECT_EQ(actual,65);
}

TEST(RobotSimulation,EmptyCommands)
{
    EXPECT_EQ(robotSim({}, {}), 0);
}

TEST(RobotSimulation,OnlyTurnsNoMovement)
{
    EXPECT_EQ(robotSim({-2, -1, -2}, {}), 0);
}

TEST(RobotSimulation,SimpleNorthMove)
{
    EXPECT_EQ(robotSim({4}, {}), 16);
}

TEST(RobotSimulation,ObstacleBlocksFirstStep)
{
    EXPECT_EQ(robotSim({1}, {{0, 1}}), 0);
}

TEST(RobotSimulation,ObstacleMidPath)
{
    EXPECT_EQ(robotSim({-1, 5}, {{3, 0}}), 4);
}

TEST(RobotSimulation,PeakBeforeFinalPosition)
{
    EXPECT_EQ(robotSim({3, -1, -1, 3}, {}), 9);
}

TEST(RobotSimulation,ObstacleAtOriginBlocksReturn)
{
    EXPECT_EQ(robotSim({1, -1, -1, 1}, {{0, 0}}), 1);
}

TEST(RobotSimulation,NoObstaclesLongPath)
{
    EXPECT_EQ(robotSim({4, -1, 4, -2, 4}, {}), 80);
}