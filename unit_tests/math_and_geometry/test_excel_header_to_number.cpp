#include "math_and_geometry/excel_header_to_number.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt


TEST(HeaderToNumber,TrivalCase)
{
    EXPECT_EQ(headerToNumber("AB"),28);
}



TEST(HeaderToNumber,LastAvailable)
{
    EXPECT_EQ(headerToNumber("XFD"),16384);
}
