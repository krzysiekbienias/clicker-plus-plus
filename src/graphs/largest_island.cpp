#include <vector>
#include <array>
#include <unordered_map>

#include "matrix/is_within_bounds.hpp"
#include "graphs/largest_island.hpp"




GridScan prescanGrid(const std::vector<std::vector<int>> &matrix) {
    GridScan preScan {};
    for (int r = 0; r < (int)matrix.size(); ++r) {
        for (int c = 0; c < (int)matrix[r].size(); ++c) {
            if (matrix[r][c] == 0) ++preScan.land;
            else if (matrix[r][c] == 1) ++preScan.water;
        }
    }
    return preScan;
}

static constexpr std::array<std::pair<int,int>,4> directions{{ {-1,0}, {1,0}, {0,-1}, {0,1} }};

int dfsIslandsSize(std::vector<std::vector<int>> &worldGrid,int row,int col,int label) {

    worldGrid[row][col]=label;
    int size=1;
    for (auto & [dr,dc]:directions) {
        int newRow=row+dr;
        int newCol=col+dc;

        if (isWithinBounds(newRow,newCol,worldGrid) && worldGrid[newRow][newCol]==0) {
            size+=dfsIslandsSize(worldGrid,newRow,newCol,label);
        }
    }
    return size;
}

std::unordered_map<int,int> labelLand(std::vector<std::vector<int>> &matrixGrid) {
    if (matrixGrid.empty() || matrixGrid[0].empty()) throw std::invalid_argument("Empty Grid");
    std::unordered_map<int,int> islandSizeMap;
    int label=2; // 0 and 1 reserved

    for (int r=0;r<matrixGrid.size();++r) {
        for (int c=0;c<(int)matrixGrid[r].size();++c) {
            if (matrixGrid[r][c]==0) {
                int islandSize=dfsIslandsSize(matrixGrid,r,c,label);
                islandSizeMap[label]=islandSize;
                ++label;
            }
        }
    }

    return islandSizeMap;
}

int largestIsland(std::vector<std::vector<int>> worldGrid) {
    if (worldGrid.empty()||worldGrid[0].empty()) return 0;
    GridScan scan= prescanGrid(worldGrid);
    // prescan we check
    // two cases
    //1: all water -> then we may flip one cell so we return 1
    if (scan.land==0) return 1;
    //2: all land -> then all grid makes one big land
    if (scan.water==0) return scan.land;
    std::unordered_map<int,int> islandSizeMap=labelLand(worldGrid);
    //CAUTION : labelLand function modify our matrix but this is fine. we need for further following

    /*
     2 1 1
     2 2 1
     1 1 3
     */

    //light C-array to keep unique neighbors of candidate to flip.
    int bestArea=0;
    for (auto& kv : islandSizeMap) bestArea = std::max(bestArea, kv.second);
    for (int r=0;r<(int)worldGrid.size();++r) {
        for (int c=0;c<(int)worldGrid[r].size();++c) {
            if (worldGrid[r][c]!=1) continue;
            int uniq[4];
            int uniqueLabel=0; // actual number of unique labels (different lands)

            auto addUnique=[&](int id) {
                for (int i=0;i<uniqueLabel;++i) {
                    if (uniq[i]==id) return; //return means we already have this id so stop look
                }
                uniq[uniqueLabel++]=id; // add new
            };
            for (auto &[dr,dc]:directions) {
                int nr=r+dr;
                int nc=c+dc;
                if (!isWithinBounds(nr,nc,worldGrid)) continue;
                int id =worldGrid[nr][nc];
                //if we hit 2,3,4 ... so we hit the land
                if (id>1) addUnique(id);
        }
            int currentArea=1; //becasue we got 1 from flipping 1 watter
            for (int j=0;j<uniqueLabel;++j) {
                auto it=islandSizeMap.find(uniq[j]);
                if (it!=islandSizeMap.end()) currentArea+=it->second;

            }
            if (currentArea>bestArea) bestArea=currentArea;
        }
    }
    return bestArea;
}