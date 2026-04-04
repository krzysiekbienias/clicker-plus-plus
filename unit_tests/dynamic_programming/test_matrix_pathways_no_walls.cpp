#include <gtest/gtest.h>
#include "dynamic_programming/matrix_pathways_no_walls.hpp"

TEST(PathWaysInMatrix,TrivalCase)
{
    int actual=matrixPathwaysOptimal(2,3);
    EXPECT_EQ(actual,3);
}

// Przypadek brzegowy: Jeden z wymiarów to 0
TEST(PathWaysInMatrix, ZeroDimension) {
    EXPECT_EQ(matrixPathwaysOptimal(0, 5), 0);
    EXPECT_EQ(matrixPathwaysOptimal(5, 0), 0);
}

// Przypadek brzegowy: Siatka 1xN lub Nx1 (tylko jedna możliwa ścieżka)
TEST(PathWaysInMatrix, SingleLine) {
    EXPECT_EQ(matrixPathwaysOptimal(1, 10), 1);
    EXPECT_EQ(matrixPathwaysOptimal(10, 1), 1);
}

// Test symetrii i optymalizacji swap(m, n)
// Wynik powinien być taki sam bez względu na kolejność argumentów
TEST(PathWaysInMatrix, SymmetryCheck) {
    int caseA = matrixPathwaysOptimal(3, 7);
    int caseB = matrixPathwaysOptimal(7, 3);
    EXPECT_EQ(caseA, caseB);
    EXPECT_EQ(caseA, 28); // Kombinacja (3+7-2) nad (3-1) = 8 nad 2 = 28
}

// Nieco większy przypadek
TEST(PathWaysInMatrix, MediumGrid) {
    // Siatka 4x4 -> (4+4-2) nad (4-1) = 6 nad 3 = 20
    EXPECT_EQ(matrixPathwaysOptimal(4, 4), 20);
}

TEST(PathWaysInMatrix, BigGrid) {
    EXPECT_EQ(matrixPathwaysOptimal(18, 17), 1166803110);
}