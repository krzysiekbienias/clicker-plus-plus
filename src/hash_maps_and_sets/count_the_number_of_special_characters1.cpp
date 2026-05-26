#include <cctype>
#include <std_aliases.hpp>
#include <unordered_set>
#include <string>
#include <vector>

// Implement your logic here.
int numberOfSpecialChars(std::string word){
    // states:
    // 0 not seen yet
    // 1 seen small
    // 2 seen upper
    // 3 seen both
    std::vector<int> seen(26,0);
    int res=0;
    int idx=0;
    for (char ch:word){
        idx=std::tolower(ch)-'a';
        if (std::islower(ch)){
            if(seen[idx]==0) seen[idx]=1;
            else if(seen[idx]==2){
                seen[idx]=3;//seen both small and upper 
                res++;
            }
        }
        else if( std::isupper(ch)){
            if(seen[idx]==0) seen[idx]=2;
            else if(seen[idx]==1){
                seen[idx]=3;
                res++;
            } 
        }   
    }

    return res;
}