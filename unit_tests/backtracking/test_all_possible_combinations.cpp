#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>
#include <backtracking/all_possible_combinations.hpp>

using std::string;
using std::vector;

// Function under test:
// vector<string> specialStrings(const vector<string> &strArr);

//check if output is sorted as required
static bool IsLexSorted(const vector<string>& v) {
    return std::is_sorted(v.begin(), v.end());
}

static vector<string> SortedCopy(vector<string> v) {
    std::sort(v.begin(), v.end());
    return v;
}

static bool AllLenN(const vector<string>& v, int n) {
    for (const auto& s : v) if ((int)s.size() != n) return false;
    return true;
}

static bool AllCharsValid(const vector<string>& out, const vector<string>& A) {
    int n = (int)A.size();
    for (const auto& s : out) {
        if ((int)s.size() != n) return false;
        for (int i = 0; i < n; ++i) {
            if (A[i].find(s[i]) == string::npos) return false;
        }
    }
    return true;
}

TEST(SpecialStrings, SingleString_Simple) {
    vector<string> A = {"abc"};
    auto out = specialStrings(A);

    // expected exact lex order for single position: same as characters order after sorting.
    vector<string> expected = {"a", "b", "c"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, TwoStrings_SmallExact) {
    vector<string> A = {"ab", "cd"};
    auto out = specialStrings(A);

    vector<string> expected = {"ac", "ad", "bc", "bd"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, InputStringsUnsorted_ShouldStillReturnLexOrder) {
    // If implementation relies on input char order, it might fail lexicographic requirement.
    vector<string> A = {"ba", "dc"};
    auto out = specialStrings(A);

    ASSERT_TRUE(IsLexSorted(out));

    // Exact set expected (lex order).
    vector<string> expected = {"ac", "ad", "bc", "bd"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, DuplicateCharactersInA_ShouldDuplicateOutputs) {
    // If A[i] contains duplicates, "all possible" strings include duplicates.
    std::vector<std::string> A = {"aab", "cc"};
    auto out = specialStrings(A);

    ASSERT_TRUE(IsLexSorted(out));
    EXPECT_TRUE(AllLenN(out, 2));
    EXPECT_TRUE(AllCharsValid(out, A));

    // Total combos = |"aab"| * |"cc"| = 3 * 2 = 6.
    // With sorted per-position choices: first "aab", second "cc":
    // outputs: "ac", "ac", "ac", "ac", "bc", "bc"
    std::vector<std::string> expected = {"ac", "ac", "ac", "ac", "bc", "bc"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, DuplicateCharactersAcrossPositions_ShouldProduceDuplicateOutputs) {
    // "All possible" strings include duplicates when inputs contain duplicate characters.
    std::vector<std::string> A = {"aa", "aa"};
    auto out = specialStrings(A);

    // Total combos = 2 * 2 = 4, all equal to "aa".
    std::vector<std::string> expected = {"aa", "aa", "aa", "aa"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, ContainsSpacesAndSymbols) {
    vector<string> A = {"a ", "b!"};
    auto out = specialStrings(A);

    // lex order with space is smaller than letters in ASCII.
    vector<string> expected = {" b", " !", "ab", "a!"};
    // Wait: compute carefully. All combos:
    // first: 'a' or ' ' ; second: 'b' or '!'
    // strings: "ab", "a!", " b", " !"
    // lex sort: " !" , " b", "a!", "ab"
    expected = {" !", " b", "a!", "ab"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, EmptyStringInA_MakesNoSolutions) {
    vector<string> A = {"ab", "", "cd"};
    auto out = specialStrings(A);

    EXPECT_TRUE(out.empty());
}

TEST(SpecialStrings, EmptyArray_NEqualsZero_ReturnsSingleEmptyString) {
    // Edge case: N=0. By definition, strings of length 0 -> one combination: "".
    vector<string> A = {};
    auto out = specialStrings(A);

    vector<string> expected = {};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, CorrectLengthAndValidity_Properties) {
    vector<string> A = {"ab", "x", "yz"};
    auto out = specialStrings(A);

    EXPECT_TRUE(IsLexSorted(out));
    EXPECT_TRUE(AllLenN(out, (int)A.size()));
    EXPECT_TRUE(AllCharsValid(out, A));

    // Count should be 2*1*2 = 4
    EXPECT_EQ((int)out.size(), 4);
}

TEST(SpecialStrings, MediumExact_ThreePositions) {
    vector<string> A = {"ab", "cd", "e"};
    auto out = specialStrings(A);

    vector<string> expected = {"ace", "ade", "bce", "bde"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, LexOrderAcrossManyPositions_NotJustByGenerationOrder) {
    // Some generation strategies produce correct set but not lex sorted.
    vector<string> A = {"cba", "21"};
    auto out = specialStrings(A);

    ASSERT_TRUE(IsLexSorted(out));
    EXPECT_TRUE(AllCharsValid(out, A));

    // Unique first chars: a,b,c; second: 1,2 => 6 outputs in lex order:
    vector<string> expected = {"a1", "a2", "b1", "b2", "c1", "c2"};
    EXPECT_EQ(out, expected);
}

TEST(SpecialStrings, LargeCount_JustCheckPropertiesAndSize) {
    // Big-ish: 5 positions, each 4 unique chars => 4^5 = 1024 strings.
    vector<string> A = {"abcd", "bcde", "cdef", "defg", "efgh"};
    auto out = specialStrings(A);

    EXPECT_EQ((int)out.size(), 1024);
    EXPECT_TRUE(IsLexSorted(out));
    EXPECT_TRUE(AllLenN(out, (int)A.size()));
    EXPECT_TRUE(AllCharsValid(out, A));
}

TEST(SpecialStrings, LargeWithDuplicatesInEachPosition_CountUsesAllCharacters) {
    // "All possible" uses the full length of each A[i], including duplicates:
    // each position has 4 choices => 4^6 = 4096
    std::vector<std::string> A = {"aaab", "bbbc", "ccca", "aaac", "bbba", "cccb"};
    auto out = specialStrings(A);
    // for (int i = 1; i < (int)out.size(); ++i) {
    //     if (out[i-1] > out[i]) {
    //         std::cerr << "LEX BREAK at i=" << i
    //                   << " prev=" << out[i-1]
    //                   << " cur="  << out[i] << "\n";
    //         break;
    //     }
    // }

    SCOPED_TRACE("size=" + std::to_string(out.size()));
    EXPECT_EQ((int)out.size(), 4096);
    EXPECT_TRUE(IsLexSorted(out));
    EXPECT_TRUE(AllCharsValid(out, A));
}

TEST(SpecialStrings, StressLex_BoundariesOfAscii) {
    // Mix digits, uppercase, lowercase to ensure true lex compare on full string.
    vector<string> A = {"aA0", "zZ9"};
    auto out = specialStrings(A);

    EXPECT_TRUE(IsLexSorted(out));
    EXPECT_TRUE(AllCharsValid(out, A));

    // Ensure the very first and very last are as expected under ASCII lex ordering.
    // Unique sorted chars: first pos {'0','A','a'}, second pos {'9','Z','z'}
    EXPECT_EQ(out.front(), "09");
    EXPECT_EQ(out.back(), "az");
}

