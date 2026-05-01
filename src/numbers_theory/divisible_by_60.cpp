#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
bool divisibleBy60(std::vector<int> nums)
{
    //60=2^2*3*5
    bool count0 =false;
    int zerosCounter=0;
    bool sumDigitsDiv3=false ;
    int sumDigits=0;


    bool existsEven=false;

    for (int x : nums)
    {
        sumDigits+=x;
        if (x==0) zerosCounter++;
        if (x%2==0 and x>0) existsEven=true;

    }
    if (zerosCounter==nums.size()) return true;
    if (sumDigits%3==0)
    {
        sumDigitsDiv3=true;
    }

    if (zerosCounter>0)
    {
        count0=true;
    }

    return (count0 && sumDigitsDiv3 && (zerosCounter>=2 || existsEven));

}