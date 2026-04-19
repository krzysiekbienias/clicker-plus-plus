#include "bit_manipulation/repeated_dna_sequences.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"

TEST(DNASequence,TrivalCase)
{
    std::string input="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    std::vector<std::string>actual=findRepeatedDnaSequences(input);
    std::vector<int> expected={"AAAAACCCCC","CCCCCAAAAA"};


}