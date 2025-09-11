# pragma once
#include<vector>
#include<cmath>
#include <regex>
#include<unordered_map>

int apartmentHunting(std::vector<std::unordered_map<std::string, bool> > blocks, std::vector<std::string> requirements);

/**
 * @brief Computes the minimum distance from each block to the nearest block
 *        that satisfies a given requirement.
 *
 * This function scans through a sequence of blocks (city blocks, offices, apartments, etc.),
 * where each block is represented as a mapping of requirement names (string) to booleans (true = present).
 * For a specified requirement, the function calculates, for each block, the shortest distance
 * (in terms of index difference) to a block where that requirement is satisfied.
 *
 * The algorithm performs two passes:
 *  - A forward pass (left → right) to compute tentative distances to the nearest requirement occurrence.
 *  - A backward pass (right → left) to refine those distances by considering requirement occurrences on the right.
 *
 * @param blocks A vector of unordered maps, where each map describes a block
 *        and maps requirement names (string) to availability flags (bool).
 * @param req The requirement key to check for (e.g., "gym", "school", "store").
 *
 * @return A vector of integers, where each element corresponds to a block and
 *         contains the minimum distance (in indices) to the nearest block that
 *         satisfies the given requirement.
 *
 * @note If the requirement is not present in any block, the results may contain
 *       very large values due to initialization with INT_MAX.
 *
 * @complexity Time: O(n), where n = number of blocks.
 *             Space: O(n) for the result vector.
 */
std::vector<int> getMinDistances(const std::vector<std::unordered_map<std::string, bool> > &blocks,
                                 const std::string &req);

std::vector<int> getMaxDistancesAtBlocks(const std::vector<std::unordered_map<std::string, bool> > &blocks,
                                         const std::vector<std::vector<int> >&minDistancesFromBlocks);
int getIdxAtMinValue(std::vector<int> arr);

inline int distance(int x, int y) {
    return abs(x - y);
}
