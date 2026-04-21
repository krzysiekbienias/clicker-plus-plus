#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int hIndexSorting(vector<int>& citations) {
    int n=citations.size();
    sort(citations.rbegin(),citations.rend());
    for(int i=0;i<citations.size();i++){
        if(citations[i]<i+1){
            return i;
        }
    }
    return n;
}


int hIndex(const vector<int>& citations)
{
    int n=citations.size();
    vector<int> res(n,0);
    vector<int> buckets(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        if (citations[i]>n)
        {
            buckets[n]++;
        }
        else
        {
            buckets[citations[i]]++;
        }
    }
    int totalPapers=0;
    for (int i=n;i>=0;i--)
    {
    totalPapers+=buckets[i];
    //totalPapers to liczba prac, które mają co najmniej i cytowań.
    if (totalPapers>=i)
    {
        return i;
    }
    }
    return n-1;
}