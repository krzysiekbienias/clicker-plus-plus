#include "std_aliases.hpp"

using namespace stl;

int repeatedNumber(const vector<int> &A) {
    int n = (int)A.size();
    if (n < 2) return -1;                 // nic do szukania

    auto in_range = [&](int v){ return 1 <= v && v < n; };  // wartości powinny być w [1..n-1]

    // Faza 1: znajdź punkt w cyklu
    int slow = A[0];
    if (!in_range(slow)) return -1;
    int fast = A[0];

    do {
        slow = A[slow];
        if (!in_range(slow)) return -1;

        fast = A[fast];
        if (!in_range(fast)) return -1;
        fast = A[fast];
        if (!in_range(fast)) return -1;
    } while (slow != fast);

    // Faza 2: wejście do cyklu = duplikat (wartość)
    slow = A[0];
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;   // to jest powtarzająca się wartość
}
