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

/**
 * @brief Computes the maximum distance at each block across all requirements.
 *
 * Given a list of blocks (each represented by a map of requirement → availability),
 * and a matrix of minimum distances (one vector per requirement), this function
 * aggregates the distances by block. For each block index `i`, it collects the
 * minimum distances to all requirements and then takes the maximum among them.
 *
 * Intuition:
 * - `minDistancesFromBlocks` has one row per requirement, where each row contains
 *   the minimum distance from every block to the nearest block that satisfies that requirement.
 * - For a block to be "good", it must be reasonably close to *all* requirements.
 * - Therefore, the "score" for a block is the maximum of these minimum distances:
 *   the farthest requirement that block still has to cover.
 *
 * @param blocks A vector of unordered maps representing blocks with their
 *        requirements (not directly used here except for sizing).
 * @param minDistancesFromBlocks A 2D vector, where each inner vector contains
 *        the minimum distances (per block) for a specific requirement.
 *
 * @return A vector of integers, where each element corresponds to a block
 *         and contains the maximum distance to the nearest requirement
 *         (worst-case requirement distance for that block).
 *
 * @complexity Time: O(r * n), where r = number of requirements
 *              (rows in minDistancesFromBlocks) and n = number of blocks.
 *             Space: O(r) for the temporary vector at each block iteration.
 *
 * @note The result is often used to select the optimal block (the one minimizing
 *       this maximum distance across all blocks).
 */
std::vector<int> getMaxDistancesAtBlocks(const std::vector<std::unordered_map<std::string, bool> > &blocks,
                                         const std::vector<std::vector<int> >&minDistancesFromBlocks);

/**
 * @brief Finds the index of the minimum value in a vector of integers.
 *
 * This function iterates through the provided vector, keeping track of the
 * smallest value encountered so far and its corresponding index. At the end
 * of the traversal, the index of the first occurrence of the minimum value
 * is returned.
 *
 * Typical use case:
 * - Given a collection of scores, distances, or other integer values,
 *   this function can be used to identify the position of the optimal
 *   (lowest) element.
 *
 * @param arr A vector of integers to search through. The vector is passed
 *        by value, but it is not modified.
 *
 * @return The index of the minimum value in the input vector.
 *         If multiple elements share the same minimum value, the index of
 *         the first occurrence is returned.
 *
 * @complexity Time: O(n), where n = size of the vector.
 *             Space: O(1), uses only constant extra storage.
 *
 * @note If the input vector is empty, behavior is undefined. It is the
 *       caller's responsibility to ensure the input is non-empty.
 */
int getIdxAtMinValue(std::vector<int> arr);

inline int distance(int x, int y) {
    return abs(x - y);
}
