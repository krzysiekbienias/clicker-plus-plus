#include "sorting/counting_sort.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

// Implement your logic here.
vector<int> countingSort(const vector<int> &arr, int maxVal){
    const int n =arr.size();
    vector<int> freqCounter(maxVal+1,0);
    vector<int> sorted(n);
    vector<int> prefixSum(maxVal+1,0);

    //count_occurence
    for (int i = 0; i < n; i++) {
        freqCounter[arr[i]]++;
    }
    //prefix sum
    prefixSum[0]=freqCounter[0];

    for (int v = 1; v <= maxVal; v++) {
        prefixSum[v]=prefixSum[v-1]+freqCounter[v];
    }

    for (int i=n-1;i>=0;i--){
        int el=arr[i];
        prefixSum[el]--;
        sorted[prefixSum[el]]=el;
    }
    return sorted;
}