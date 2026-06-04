#include "simulations/sequential_digits.hpp"

#include <algorithm>
#include <string>

std::vector<int> sequentialDigits(int low, int high)
{
    std::vector<int> res;
    const int lowSize = static_cast<int>(std::to_string(low).size());
    const int highSize = static_cast<int>(std::to_string(high).size());

    const int minLength = std::max(lowSize, 2);
    for (int length = minLength; length <= highSize; ++length) {
        for (int i = 1; i <= 10 - length; ++i) {
            int num = 0;
            for (int j = 0; j < length; ++j) {
                num = num * 10 + (i + j);
            }
            if (num >= low && num <= high) {
                res.push_back(num);
            }
        }
    }
    return res;
}
