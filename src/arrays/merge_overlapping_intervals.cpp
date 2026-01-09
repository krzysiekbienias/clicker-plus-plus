#include <std_aliases.hpp>
#include <arrays/merge_overlapping_intervals.hpp>
using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals)
{
    if (intervals.empty()) return {};
    int n = intervals.size();
    vector<vector<int>> results;
    //we need to make sure that intervals are sorted by start of the interval.
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int>& a, const vector<int>& b)
              {
                  return a[0] < b[0];
              });
    int currentStart = intervals[0][0];
    int currentEnd = intervals[0][1];
    for (int i = 1; i < n; ++i)
    {
        int nextStart = intervals[i][0];
        int nextEnd = intervals[i][1];
        if (nextStart > currentEnd)
        {
            results.push_back({currentStart, currentEnd});
            currentStart = nextStart;
            currentEnd = nextEnd;
        }
        else
        {
            currentEnd = std::max(currentEnd, nextEnd);
        }
    }
    results.push_back({currentStart, currentEnd});

    return results;
}


std::vector<Interval> mergeOverlappingIntervalsInterBit(std::vector<Interval> intervals)
{
    if (intervals.empty()) return {};
    int n = intervals.size();
    vector<Interval> results;
    //we need to make sure that intervals are sorted by the start of the interval.
    std::sort(intervals.begin(), intervals.end(),
              [](const Interval& a, const Interval& b)
              {
                  return a.start < b.start;
              });
    int currentStart = intervals[0].start;
    int currentEnd = intervals[0].end;
    for (int i = 1; i < n; ++i)
    {
        int nextStart = intervals[i].start;
        int nextEnd = intervals[i].end;
        if (nextStart > currentEnd)
        {
            results.push_back(Interval{currentStart, currentEnd});
            currentStart = nextStart;
            currentEnd = nextEnd;
        }
        else
        {
            currentEnd = std::max(currentEnd, nextEnd);
        }
    }
    results.push_back(Interval{currentStart, currentEnd});
    return results;
}
