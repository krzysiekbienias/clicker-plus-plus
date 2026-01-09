#pragma once

#include <string>
#include <vector>

struct Interval
{
    int start;
    int end;
    Interval():start(0),end(0){};
    Interval(int s,int e):start(s),end(e){}
};

inline bool operator==(const Interval& a,const Interval& b)
{
    return a.start==b.start && a.end==b.end;
}


std::vector<std::vector<int>> mergeOverlappingIntervals(std::vector<std::vector<int>> intervals);

std::vector<Interval> mergeOverlappingIntervalsInterBit(std::vector<Interval> intervals);
