#include "matrix/find_center.hpp"
#include <gtest/gtest.h>


TEST(FindCenter, CenterExists)
{
    std::optional<int> res = center({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res, 5);
}

TEST(FindCenter, NoCenter)
{
    std::optional<int> res = center({{1, 2}, {4, 5}});

    EXPECT_EQ(res, std::nullopt);
}

TEST(FindCenter, EmptyMat)
{
    std::optional<int> res = center({{}});

    EXPECT_EQ(res, std::nullopt);
}
