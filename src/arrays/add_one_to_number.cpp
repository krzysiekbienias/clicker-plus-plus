#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

vector<int> plusOne(vector<int>& digits) {
    if (digits.empty())
    {
        return {};
    }
    int i=0;
    while (i<digits.size() && digits[i]==0) ++i;
    digits.erase(digits.begin(),digits.begin()+i);
    //erase ok becasue only run removing leading zeros

    int n=digits.size();
    int lastDigit=digits.back();
    if (lastDigit<9 && digits[0]!=0){
        lastDigit++;
        digits.back()=lastDigit;
        return digits;
    }

    //remove all 9s
    int dropCounter=0;
    while (!digits.empty() && digits.back()==9  )
    {   digits.pop_back();
        dropCounter++;

    }
    //999
    if (digits.empty()){
        digits.push_back(1);
        for(i=1;i<=n;++i)
        {
            digits.push_back(0);
        }
        return digits;

    }

    //1299,899
    digits.back()++;

    for (int i=0;i<dropCounter;++i){
        digits.push_back(0);
    }
    return digits;
}
