#include <stack>
#include <vector>
// Implement your daily_temperatures logic here.
std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    std::vector<int> answer(temperatures.size(), 0);      // zeros handles no warmer dau case by default.
    std::stack<int> st;                                   // it stores indices
    for (int i = temperatures.size() - 1; i >= 0; --i) {  // we are moving from right to left. I'll know warmer days ahead
        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();  // popping until we find a warmer day
        }
        if (!st.empty()) {
            answer[i] = st.top() - i;  // difference in indeces
        }

        st.push(i);
    }
    return answer;
}
