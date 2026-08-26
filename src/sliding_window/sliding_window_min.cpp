#include "sliding_window/sliding_window_min.hpp"
#include <vector>
#include <string>
#include <deque>

using std::vector;
using std::string;
using std::deque;


// Implement your logic here.
vector<int> slidingWindowMin(const std::vector<int>& arr, int k){
    //[1, 3, -1, -3, 5, 3, 6, 7], k = 3

    //windows:
    //[1,3,-1] [3,-1,-3] [-1,-3,5] ...
    deque<int> dqIdx; //here we keep indices
    vector<int> res(arr.size()-k);
    for (int i=0; i<arr.size(); ++i) {
        if(!dqIdx.empty() && dqIdx.front()<=i-k){
            dqIdx.pop_front();
        }
        while(!dqIdx.empty() && arr[dqIdx.back()]>arr[i]){
            dqIdx.pop_back();
        }
        dqIdx.push_back(i);

        if(i>=k-1){
            res.push_back(arr[dqIdx.front()]);
        }
    }
    return res;

}