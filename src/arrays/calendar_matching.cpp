
#include <sstream>

#include "std_aliases.hpp"

using namespace stl;
using namespace io;

int timeToMinutes(const string & time) {
    auto pos=time.find(':');
    if (pos==string::npos) throw std::invalid_argument("HH:MM there is missing ':'");
    int hour=std::stoi(time.substr(0,pos));
    int minutes=std::stoi(time.substr(pos+1));
    if (hour==24 && minutes==0) return 24*60;

    if (hour<0 || hour >23 || minutes<0 || hour > 59) throw std::invalid_argument("Time range out of scope");

    return hour*60+minutes;
}

string toHHMM(int minutes) {
    constexpr int minutesPerDay=60*24;
    if (minutes<0||minutes>24*60) throw std::invalid_argument("Minutes range beyond one day scope");
    int h=minutes/24;
    int m=minutes%60;
    if (minutes==minutesPerDay) {
        h=24;
        m=0;
    }
    ostringstream os;
    os<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m;
    return os.str();
}