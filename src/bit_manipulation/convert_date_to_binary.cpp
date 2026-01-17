#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

void removeLeadingZeros(string& str)
{
    int i=0;
    while (i<str.size() && str[i]=='0')
    {
        i++;
    }
    str=str.substr(i);
}

// Implement your logic here.
string convertDateToBinary(string date)
{
    string year=date.substr(0,4);
    string month=date.substr(5,2);
    string day=date.substr(8,2);
    std::bitset<16> yearBit(stoi(year));
    std::bitset<16> monthBit(stoi(month));
    std::bitset<16> dayBit(stoi(day));
    string yearBinary=yearBit.to_string();
    string monthBinary=monthBit.to_string();
    string dayBinary=dayBit.to_string();
    removeLeadingZeros(yearBinary);
    removeLeadingZeros(monthBinary);
    removeLeadingZeros(dayBinary);
    return yearBinary+"-"+monthBinary+"-"+dayBinary;

}