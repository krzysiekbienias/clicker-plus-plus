#include <std_aliases.hpp>

using namespace stl;

double calcualateDelta(int passed,int all) {
    double delta=(double)(all-passed)/((double)all*(all+1));
    return delta;
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents){
    priority_queue<pair<double,int>> gainHeap;
    double totalRatio=0;
    double gainTotal=0;
    double initialTotalRatio=0;
    for (int i =0;i<classes.size();++i) {
        initialTotalRatio +=(double)classes[i][0]/(double)classes[i][1];
        gainHeap.emplace(calcualateDelta(classes[i][0],classes[i][1]),i);
    }

    double maxAverage=0;
    while (extraStudents>0) {
        auto [marginalGain,i]=gainHeap.top();

        gainHeap.pop();
        gainTotal+=marginalGain;
        classes[i][0]++;
        classes[i][1]++;
        double newDelta=calcualateDelta(classes[i][0],classes[i][1]);
        gainHeap.emplace(newDelta,i);
        extraStudents--;
    }
    totalRatio=(initialTotalRatio+gainTotal);
    maxAverage=totalRatio/ classes.size();
    return maxAverage;
}

