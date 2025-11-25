#include <std_aliases.hpp>
using namespace stl;

//sorting allowed
int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int need=1;
        //disregard all negative
        auto it=std::lower_bound(nums.begin(),nums.end(),1);
        for (it ;it!=nums.end();++it) {
            int x=*it;
            if (x<need){
                continue;
            }
            if (need==x) {
                need++; //
            }
            else return need;
        }
        return need;
    }
