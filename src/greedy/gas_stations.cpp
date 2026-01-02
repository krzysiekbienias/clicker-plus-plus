#include <std_aliases.hpp>
#include <numeric>

using namespace stl;

int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    if (gas.empty() or cost.empty()) return -1;
    int n = gas.size();
    if (std::accumulate(gas.begin(), gas.end(), 0) <
        std::accumulate(cost.begin(), cost.end(), 0)) {
        return -1;
    }
    int start = 0;
    int tankLevel = 0;
    for (int i = 0; i < n; ++i) {
        tankLevel += gas[i] - cost[i];
        if (tankLevel < 0) {
            start = i + 1;
            tankLevel = 0;
        }
    }
    return start;
}
