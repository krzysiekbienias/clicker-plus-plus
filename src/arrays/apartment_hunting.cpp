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
    std::vector<int> minDistancesPerRequired(blocks.size());
    int closestIndexForReq=INT_MAX;
    for (int i=0;i<blocks.size();++i) {
         if (blocks[i].at(req)) closestIndexForReq=i;
        minDistancesPerRequired[i]=distance(i,closestIndexForReq);
    }
    for (int i=blocks.size()-1;i>=0;i--) {
        if (blocks[i].at(req)) closestIndexForReq=i;
        minDistancesPerRequired[i]=std::min(minDistancesPerRequired[i],distance(i,closestIndexForReq));
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