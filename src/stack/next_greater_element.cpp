#include "stack/next_greater_element.hpp"
#include <vector>
#include <std_aliases.hpp>

using namespace stl;

// Implement your next_greater_element logic here.
std::vector<int> nextGreaterElementIterators(const std::vector<int>& array)
{
    std::vector<int> stack;
    std::vector<int> results(array.size(), 0);
    for (auto it = array.crbegin(); it != array.crend(); ++it)
    {
        int idx = std::distance(it, array.crend()) - 1;
        while (!stack.empty() && array[idx] >= stack.back())
        {
            //remove all candidates less or equal array[idx]
            stack.pop_back();
        }
        results[idx] = (!stack.empty()) ? stack.back() : -1;
        stack.push_back(array[idx]);
    }

    return results;
}


std::vector<int> nextGreaterElement(const std::vector<int>& array)
{
    vector<int> st;
    int n = static_cast<int>(array.size());
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; --i)
    {
        int x = array[i];
        while (!st.empty() && st.back() <= x)
        {
            st.pop_back();
        }
        res[i] = st.empty() ? -1 : st.back();
        // x becomes a candidate for elements on left
        st.push_back(x);
    }
    return res;
}


