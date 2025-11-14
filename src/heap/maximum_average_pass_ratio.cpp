#include <std_aliases.hpp>

using namespace stl;

double calcualateDelta(int passed,int all) {
    long double t=(long double) all;
    return double(all-passed)/(t*(t+1.0L));
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents){
    priority_queue<pair<double,int>> startingRatio;
    for (int i =0;i<classes.size();++i) {
        startingRatio.emplace(calcualateDelta(classes[i][0],classes[i][1]),i);
    }
    double sum=0;
    while (extraStudents>0) {
        auto [g,i]=startingRatio.top();

        startingRatio.pop();
        sum+=g;
        classes[i][0]++;
        classes[i][1]++;
        startingRatio.emplace(calcualateDelta(classes[i][0],classes[i][1]),i);
        extraStudents--;
    }

    return (double) sum/ classes.size();
}

