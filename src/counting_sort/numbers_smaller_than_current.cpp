#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


vector<int> smallerNumbersThanCurrentBF(const vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,0);
    for (int i=0;i<n;i++){
        int temp=0;
        for (int j=0;j<n;j++){
            if(nums[j]<nums[i]) temp++;
        }
        res[i]=temp;
    }
    return res;

}

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,0);
    int maxElement=*max_element(nums.begin(),nums.end());
    vector<int> smallerThan(maxElement+1,0);
    vector<int> buckets(maxElement+1,0);
    for( int x:nums){
        buckets[x]++;
    }
    for (int i=1;i<=maxElement; i++){
        smallerThan[i]=buckets[i-1]+smallerThan[i-1];
    }

    for (int i=0;i<n;i++){
        res[i]=smallerThan[nums[i]];
    }
    return res;
}