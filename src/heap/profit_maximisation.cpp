#include<std_aliases.hpp>

using namespace stl;
int profitMaximisation(const vector<int> &tickets, int k) {
    if (tickets.empty()||k==0) return 0;
    priority_queue<int> pq; //maxHeap
    for (int ticket:tickets) {
        pq.push(ticket);
    }
    int maxProfit=0;
    int i=0;
    while (i<k && pq.top()>0) {
        int top=pq.top();
        maxProfit+=top;
        top--;
        pq.pop();
        pq.push(top);
        i++;
    }
    return maxProfit;
}

