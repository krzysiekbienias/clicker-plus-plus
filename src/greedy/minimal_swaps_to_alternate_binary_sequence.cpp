#include <climits>
#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


static  int countMismatch(const std::string & s,char startChar){
    int mismatches=0;
    size_t n=s.size();
    for (int i = 0; i < n; i++) {
        char expected;
        if (i%2==0){
            expected=startChar;
        }
        else{
            expected=(startChar=='1')?'0':'1';
        }
        if(s[i]!=expected){
            mismatches++;
        }
    }
    return mismatches;
}

int minSwaps(std::string s) {
   int nbOf1s=0;
   int nbOf0s=0;
   int res=INT_MAX;
   for (const auto& elem : s) {
        if (elem=='1'){
            nbOf1s++;
        }
        else{
            nbOf0s++;
        }
   }
   if (abs(nbOf0s-nbOf1s)>1){
    return -1;
   }
   int v1=0;
   int v2=0;

   if (nbOf1s>nbOf0s){
    res= countMismatch(s, '1');
    
   }
   else if (nbOf0s>nbOf1s){
    res= countMismatch(s, '0');
   }
   else{
    v1=countMismatch(s, '1');
    v2=countMismatch(s, '0');
    res= std::min(v1,v2);
   }
   return res/2;

  }
