#include "arrays/majority_element.hpp"
#include <vector>
#include <unordered_map>

// Implement your majority_element logic here.
int majorityElement(std::vector<int>& nums){
    int n=nums.size();
    std::unordered_map<int , int> elementOccurence;
    for(int num:nums){
        elementOccurence[num]++;
    }
    for (auto &[key,value]:elementOccurence){
        if (value>n/2) {
            return key;
        }
    }
    return -1;
}

//unique majority element granted
int majorityElementBoyerMoore(const std::vector<int>& nums) {
    int candidate=-1;
    int count=0;
    for (int num:nums) {
        if (count==0) {
            candidate=num;
            count=1;
        }
        else if (num==candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return candidate;
}



int majorityElementBoyerMooreGeneralSolution(const std::vector<int>& nums) {
    int candidate=0;
    int count =0;
    for (int num:nums) {
        if (count==0) {
            candidate=num;
            count=1;
        }
        else if (num==candidate) ++count;
        else --count;
    }
    int occur=0;
    for (int num:nums) if (num==candidate) ++occur;

    return (occur>static_cast<int>(nums.size()/2))? candidate:-1;
}