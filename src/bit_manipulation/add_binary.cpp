#include <std_aliases.hpp>


using namespace stl;
using namespace io;
using namespace str;

std::string addBinary(std::string a, std::string b)
{
    string res;
    int i=a.length()-1;
    int j=b.length()-1;

    int carry=0;
    while (i>=0||j>=0||carry>0)
    {
        int bit_a=a[i]-'0';
        int bit_b=b[j]-'0';

        int sumOfBits=bit_a+bit_b+carry;

        int newBit=sumOfBits%2;
        carry=carry/2;

        res+=std::to_string(newBit);
    }
    std::reverse(res.begin(),res.end());
    return res;
}
