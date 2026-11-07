#include "greedy/jump_game_II.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

int jump(std::vector<int>& nums){
    int n=nums.size();
    int nb_jumps=0;
    int current_end=0;
    int max_reach=0;

    for (int i = 0; i < n-1; i++) {
        max_reach=std::max(i+nums[i],max_reach);
        if (i==current_end){
            nb_jumps++;
            current_end=max_reach;
        }
    }
    return nb_jumps;
}
