#include <std_aliases.hpp>
#include "bit_manipulation/minimize_xor.hpp"

// Implement your logic here.
int minimizeXor(int num1, int num2) {
    int nbOfSetBits1=__builtin_popcount(num1);
    int nbOfSetBits2Budget=__builtin_popcount(num2);
    int x=0;
    //1s more than required
    bool needAdd1s=(nbOfSetBits1<nbOfSetBits2Budget);

    if (needAdd1s)
    {
        int k=nbOfSetBits2Budget-nbOfSetBits1;
        //fill from right the least significance
        x=num1;
        for (int i = 0; i <= 31; ++i) {
            // Tu operujemy na i-tym bicie, zaczynając od 0 (prawa strona)
            if ((x&(1<<i))==0 && k>0)
            {
                (x|=(1<<i));
                k--;
            }
        }
    }
    else
    {   int k=0;
        //x=num2; trap! 🚩
        //we may start with the smallest possible number so zero and we build x from scratch
        for (int i = 31; i >=0; --i)
        {
            if ((num1&(1<<i))!=0 && k<nbOfSetBits2Budget)
            {
                (x|=(1<<i));
                k++;
            }
        }
    }
    return x;
}

