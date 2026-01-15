#include "two_pointers/subarrays_with_distinct_integers.hpp"
#include <gtest/gtest.h>

TEST(SubarraysWithDistinctIntegers,TrivalCase)
{
    std::vector<int> v={1,2,1,3,4};

    int x=atMostKDistinct(v,3);
    std::cout<<"At most 3 distinct ="<<x;
    int y=atMostKDistinct(v,2);
    std::cout<<"At most 2 distinct  ="<<y;
    // [1, 2, 1, 3], [2, 1, 3], [1, 3, 4].
    EXPECT_EQ(exactKDistinct(v,3),3);

}

TEST(SubarraysWithDistinctIntegers, EmptyArray)
{
    std::vector<int> v{};
    EXPECT_EQ(exactKDistinct(v, 1), 0);
    EXPECT_EQ(exactKDistinct(v, 0), 0); // jak wspierasz k=0 -> tylko "pusty" nie liczymy, więc 0
}

TEST(SubarraysWithDistinctIntegers, SingleElement)
{
    std::vector<int> v{7};
    EXPECT_EQ(exactKDistinct(v, 1), 1); // [7]
    EXPECT_EQ(exactKDistinct(v, 2), 0);
}

TEST(SubarraysWithDistinctIntegers, AllSameElements)
{
    std::vector<int> v{5,5,5,5};
    // wszystkie podtablice mają dokładnie 1 distinct
    // liczba subarray = n*(n+1)/2 = 4*5/2 = 10
    EXPECT_EQ(exactKDistinct(v, 1), 10);
    EXPECT_EQ(exactKDistinct(v, 2), 0);
}

TEST(SubarraysWithDistinctIntegers, AllDistinctSmall)
{
    std::vector<int> v{1,2,3,4};
    // dokładnie 1 distinct: tylko single
    EXPECT_EQ(exactKDistinct(v, 1), 4);

    // dokładnie 2 distinct: długość 2 subarrays: [1,2],[2,3],[3,4]
    EXPECT_EQ(exactKDistinct(v, 2), 3);

    // dokładnie 3 distinct: długość 3 subarrays: [1,2,3],[2,3,4]
    EXPECT_EQ(exactKDistinct(v, 3), 2);

    // dokładnie 4 distinct: [1,2,3,4]
    EXPECT_EQ(exactKDistinct(v, 4), 1);
}

TEST(SubarraysWithDistinctIntegers, KGreaterThanUniqueCount)
{
    std::vector<int> v{1,2,1,2};
    // unique = 2, więc k=3 nic nie da
    EXPECT_EQ(exactKDistinct(v, 3), 0);
    EXPECT_EQ(exactKDistinct(v, 4), 0);
}

TEST(SubarraysWithDistinctIntegers, AlternatingTwoValues)
{
    std::vector<int> v{1,2,1,2,1};
    // dokładnie 1 distinct: tylko single = 5
    EXPECT_EQ(exactKDistinct(v, 1), 5);

    // dokładnie 2 distinct: wszystkie subarrays o długości >=2 (bo w takim układzie zawsze wpadają oba)
    // liczba wszystkich subarray = 5*6/2 = 15, minus single = 5 => 10
    EXPECT_EQ(exactKDistinct(v, 2), 10);
}

TEST(SubarraysWithDistinctIntegers, MediumWithRepeats)
{
    std::vector<int> v{1,2,1,3,4};
    // z Twojego przykładu: dokładnie 3 distinct = 3
    EXPECT_EQ(exactKDistinct(v, 3), 3);

    // dodatkowo: dokładnie 2 distinct
    // ręcznie wychodzi 5: [1,2],[1,2,1],[2,1],[1,3],[3,4]
    EXPECT_EQ(exactKDistinct(v, 2), 5);

    // dokładnie 4 distinct: [1,2,1,3,4] i [2,1,3,4] => 2
    EXPECT_EQ(exactKDistinct(v, 4), 2);
}

TEST(SubarraysWithDistinctIntegers, ClassicExample)
{
    std::vector<int> v{1,2,1,2,3};
    // znany przykład: dokładnie 2 distinct = 7
    EXPECT_EQ(exactKDistinct(v, 2), 7);

    // dokładnie 3 distinct = 3: [1,2,1,2,3], [2,1,2,3], [1,2,3]
    EXPECT_EQ(exactKDistinct(v, 3), 3);
}