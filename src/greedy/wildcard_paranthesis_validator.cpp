#include "greedy/wildcard_paranthesis_validator.hpp"
#include <string>


using std::string;

// Implement your logic here.
bool wildcard_parenthesis_validator(std::string str){
    int low=0; //the smallest possible number of unmatched
    int high=0; //the largest possible number of unmatched
     for (char ch:str)
     {
         if (ch=='(')
         {
             low++;
             high++;
         }
         else if (ch==')')
         {
             low--;
             high--;
             if (high<0) return false;
         }
         else
         {
             low--;
             high++;
         }
    if (high<0) return false;
    low=std::max(0,low);
     }
    
    return low==0;
  }