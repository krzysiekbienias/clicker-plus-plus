#pragma once
#include "std_aliases.hpp"

using namespace stl;

struct StringMeeting {
    string start;
    string end;
};

//represents mathematical integral where X is a day span expressed in minutes
struct Interval {
    int start;
    int end;

};

int timeToMinutes(const string & time);
string toHHMM(int minutes);


