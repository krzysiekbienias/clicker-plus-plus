#include "arrays/filling_jars.hpp"
#include <gtest/gtest.h>
#include <fstream>


static std::pair<int, std::vector<std::vector<int>>>
readFillingJarsFile(const std::string& path)
{
    std::ifstream in(path);
    //data/hacker_rank_input_for_ut/filling_jars.txt
    if (!in.is_open()) {
        throw std::runtime_error("Cannot open input file: " + path);
    }

    int n = 0, m = 0;
    in >> n >> m;

    std::vector<std::vector<int>> operations;
    operations.reserve(m);

    for (int i = 0; i < m; ++i) {
        int a, b, k;
        in >> a >> b >> k;
        operations.push_back({a, b, k});
    }

    return {n, std::move(operations)};
}


TEST(FillingJars,Trival_Case)
{
    int n=5;
    std::vector<std::vector<int>> operations={
        {1,2,100},
        {2,5,100},
        {3,4,100}
    };
    EXPECT_EQ(fillingJarsBF(5,operations),160);
}

TEST (FillingJars,BigSample)
{
    const std::string path="data/hacker_rank_input_for_ut/filling_jars.txt";
    auto [n,operations]=readFillingJarsFile(path);
    //sanity check
    ASSERT_GT(n,0);
    ASSERT_FALSE(operations.empty());

    long long actual=fillingJarsBF(n,operations);
    long long expected=4991588628;
    EXPECT_EQ(actual,expected);

}
