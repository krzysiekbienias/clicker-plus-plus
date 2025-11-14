# include<unordered_set>

int nextSumSquares(int x) {
    int sum=0;
    while (x>0) {
        int digit =x%10;
        sum+=digit*digit;
        x/=10;
    }
    return sum;
}

bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n!=1 && !seen.count(n)) {
        seen.insert(n);
        n=nextSumSquares(n);
    }
    return n==1;
}