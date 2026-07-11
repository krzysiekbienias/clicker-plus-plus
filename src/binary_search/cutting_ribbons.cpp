#include <vector>

// Implement your logic here.
bool canCut(int x, int k, const std::vector<int>& ribbons) {
    if (x == 0)
        return false;
    int countPieces = 0;
    for (int len : ribbons) {
        countPieces += len / x;
        if (countPieces >= k)
            return true; // early exit
    }
    return countPieces >= k;
}

int maxLength(std::vector<int>& ribbons, int k) {
    int left = 1; // becasue we need to divide
    int right = *std::max_element(ribbons.begin(), ribbons.end());
    int res = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canCut(mid, k, ribbons)) {
            left = mid + 1;
            res = mid;
        } else {
            right = mid - 1;
        }
    }
    return res;
}