#include <vector>

bool cutsEnoughWood(int setHeight, int k, const std::vector<int>& heights){
    int collected_wood=0;
    for (const auto& height : heights) {
        if (height>setHeight){
            collected_wood+=(height-setHeight);// od gory tniemy ten drzewo
        }
    }
    return collected_wood>=k;
}

int cuttingWood(const std::vector<int>& heights,int k){
    int res=0;
    int left=0;
    int right=*std::max_element(heights.begin(),heights.end());
   
    while(left<=right){
        int mid =left+(right-left)/2;
        if (cutsEnoughWood(mid, k, heights)){
            left=mid+1;
            res=mid;
        }
        else{
            right=mid-1;
        }
        
    }
    return res;
}