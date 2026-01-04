#include <std_aliases.hpp>

using namespace stl;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
    sort(redShirtHeights.begin(),redShirtHeights.end());
    sort(blueShirtHeights.begin(),blueShirtHeights.end());
    //decide which colour is in forst row: the pupils with lower the lowest student.
    int lowestRed=redShirtHeights.front();
    int lowestBlue=blueShirtHeights.front();

    int n=redShirtHeights.size();
    if (n==1 && lowestRed==lowestBlue) return false;
    if (n==1 && lowestRed!=lowestBlue) return true;
    // red in first row
    if (lowestRed<=lowestBlue && n>1) {
        for (int i=1;i<n;++i) {
            if (redShirtHeights[i]>=blueShirtHeights[i]) return false;
        }
    }
    if (lowestBlue<=lowestRed && n>1) {
        for (int i=1;i<n;++i) {
            if (redShirtHeights[i]<=blueShirtHeights[i]) return false;
        }
    }
    return true;

}