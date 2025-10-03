#include<vector>
#include "arrays/apartment_hunting.hpp"

int apartmentHunting(std::vector<std::unordered_map<std::string,bool>> blocks, std::vector<std::string>requirements) {
    std::vector<std::vector<int>> minDistancesFromAllBlocks;
    minDistancesFromAllBlocks.reserve(requirements.size());
for (const std::string& req:requirements) {
        minDistancesFromAllBlocks.push_back(getMinDistances(blocks,req));
    }
    std::vector<int> maxDistancesAtBlocks=getMaxDistancesAtBlocks(blocks,minDistancesFromAllBlocks);
    return getIdxAtMinValue(maxDistancesAtBlocks);
}

std::vector<int> getMinDistances(const std::vector<std::unordered_map<std::string,bool>>& blocks,const std::string& req) {

    int const INF =10e6;
    std::vector<int> minDistancesPerRequired(blocks.size(),INF);
    int closestIndexForReq=INF;

    for (int i=0;i<blocks.size();++i) {
         auto it =blocks[i].find(req);
         if(it!=blocks[i].end() && it->second) closestIndexForReq =i;
         if(closestIndexForReq!=INF) minDistancesPerRequired[i]=i-closestIndexForReq;
    }

    closestIndexForReq=INF;//reset required
    for (int i=blocks.size()-1;i>=0;--i) {
        auto it =blocks[i].find(req);
        if(it!=blocks[i].end() && it->second) closestIndexForReq=i;
        if (closestIndexForReq!=INF) minDistancesPerRequired[i]=std::min(minDistancesPerRequired[i],closestIndexForReq-i);
    }
    return minDistancesPerRequired;
}


std::vector<int> getMaxDistancesAtBlocks(const std::vector<std::unordered_map<std::string, bool> > &blocks,
                                         const std::vector<std::vector<int> >&minDistancesFromBlocks) {
    std::vector<int> maxDistancesAtBlocks(blocks.size());
    for (int i=0;i<blocks.size();++i) {
        std::vector<int> minDistancesAtBlock; // Singular one vector
        for (std::vector<int> distances:minDistancesFromBlocks) {
            minDistancesAtBlock.push_back(distances[i]);
        }
        //still in the outer loop
        maxDistancesAtBlocks[i]=*std::max_element(minDistancesAtBlock.begin(),minDistancesAtBlock.end());
    }
    return maxDistancesAtBlocks;
}
//generic application
int getIdxAtMinValue(std::vector<int> arr) {
    int indexAtMinValue=0;
    int minValue=INT_MAX;
    for (int i=0;i<arr.size();++i) {
        int currentValue=arr[i];
        if (currentValue<minValue) {
            minValue=currentValue;
            indexAtMinValue=i;
        }
    }

    return indexAtMinValue;
}