#include "hash_maps_and_sets/group_duplicated_files.hpp"
#include <gtest/gtest.h>
#include "utils/haker_rank_io.hpp"
#include <vector>
// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt
using namespace std;

namespace
{
    std::vector<std::vector<std::string>> normalize(std::vector<std::vector<std::string>> groups)
    {
        for (auto& group : groups)
        {
            std::sort(group.begin(), group.end());
        }

        std::sort(groups.begin(), groups.end());
        return groups;
    }
} // name

TEST(GroupDuplicatedFilesTest, EmptyInputReturnsEmptyResult)
{
    vector<string> paths = {};

    vector<vector<string>> actual = groupDuplicatedFiles(paths);

    EXPECT_TRUE(actual.empty());
}

TEST(GroupDuplicatedFilesTest, SingleDirectoryWithNoDuplicatesStillReturnsSingleGroupsInCurrentImplementation)
{
    vector<string> paths = {
        "root/a 1.txt(abc) 2.txt(def)"
    };

    vector<vector<string>> actual = normalize(groupDuplicatedFiles(paths));
    vector<vector<string>> expected = normalize({
        {"root/a/1.txt"},
        {"root/a/2.txt"}
    });

    EXPECT_EQ(actual, expected);
}

TEST(GroupDuplicatedFilesTest, BasicDuplicateGroupAcrossDifferentDirectories)
{
    vector<string> paths = {
        "root/a 1.txt(abc) 2.txt(def)",
        "root/b 3.txt(abc)"
    };

    vector<vector<string>> actual = normalize(groupDuplicatedFiles(paths));
    vector<vector<string>> expected = normalize({
        {"root/a/1.txt", "root/b/3.txt"},
        {"root/a/2.txt"}
    });

    EXPECT_EQ(actual, expected);
}

TEST(GroupDuplicatedFilesTest, MultipleDuplicateGroups)
{
    vector<string> paths = {
        "root/a 1.txt(aaa) 2.txt(bbb)",
        "root/b 3.txt(aaa) 4.txt(ccc)",
        "root/c 5.txt(bbb)"
    };

    vector<vector<string>> actual = normalize(groupDuplicatedFiles(paths));
    vector<vector<string>> expected = normalize({
        {"root/a/1.txt", "root/b/3.txt"},
        {"root/a/2.txt", "root/c/5.txt"},
        {"root/b/4.txt"}
    });

    EXPECT_EQ(actual, expected);
}

TEST(GroupDuplicatedFilesTest, DuplicateFilesInsideSameDirectory)
{
    vector<string> paths = {
        "root/a 1.txt(xyz) 2.txt(xyz) 3.txt(pqr)"
    };

    vector<vector<string>> actual = normalize(groupDuplicatedFiles(paths));
    vector<vector<string>> expected = normalize({
        {"root/a/1.txt", "root/a/2.txt"},
        {"root/a/3.txt"}
    });

    EXPECT_EQ(actual, expected);
}

TEST(GroupDuplicatedFilesTest, NestedDirectoriesAreHandledCorrectly)
{
    vector<string> paths = {
        "root/d1/d2 f1.txt(abc) f2.txt(def)",
        "root/d3 f3.txt(abc)"
    };

    vector<vector<string>> actual = normalize(groupDuplicatedFiles(paths));
    vector<vector<string>> expected = normalize({
        {"root/d1/d2/f1.txt", "root/d3/f3.txt"},
        {"root/d1/d2/f2.txt"}
    });

    EXPECT_EQ(actual, expected);
}

TEST(GroupDuplicatedFilesTest, DifferentFileNamesSameContentAreGroupedTogether)
{
    vector<string> paths = {
        "root/a a.txt(content)",
        "root/b b.txt(content)",
        "root/c c.txt(content)"
    };

    vector<vector<string>> actual = normalize(groupDuplicatedFiles(paths));
    vector<vector<string>> expected = normalize({
        {"root/a/a.txt", "root/b/b.txt", "root/c/c.txt"}
    });

    EXPECT_EQ(actual, expected);
}

TEST(GroupDuplicatedFilesTest, SameFileNameDifferentContentAreSeparated)
{
    vector<string> paths = {
        "root/a file.txt(abc)",
        "root/b file.txt(def)"
    };

    vector<vector<string>> actual = normalize(groupDuplicatedFiles(paths));
    vector<vector<string>> expected = normalize({
        {"root/a/file.txt"},
        {"root/b/file.txt"}
    });

    EXPECT_EQ(actual, expected);
}