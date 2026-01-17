#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

void removeLeadingZeros(string& str)
{
    int i = 0;
    while (i < str.size() && str[i] == '0')
    {
        i++;
    }
    str = str.substr(i);
}

// Implement your logic here.
string convertDateToBinary(string date)
{   if (date.empty()) return "0";
    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);
    string yearBinary=std::bitset<16> (stoi(year)).to_string();
    string monthBinary=std::bitset<16> (stoi(month)).to_string();
    string dayBinary=std::bitset<16> (stoi(day)).to_string();
    removeLeadingZeros(yearBinary);
    removeLeadingZeros(monthBinary);
    removeLeadingZeros(dayBinary);
    return yearBinary + "-" + monthBinary + "-" + dayBinary;
}
