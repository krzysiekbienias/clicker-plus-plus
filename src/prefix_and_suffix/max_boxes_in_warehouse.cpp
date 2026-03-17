#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.
int maxBoxesInWarehouse(std::vector<int> &boxes, std::vector<int> &warehouse) {
    int n=warehouse.size();
    vector<int> capacity(n,0);
    vector<int> leftMin(n);
    vector<int> rightMin(n);

    leftMin[0]=warehouse[0];
    for (int i = 1; i < n; ++i)
    {
        leftMin[i]=std::min(leftMin[i-1],warehouse[i]);
    }
    rightMin[n-1]=warehouse[n-1];
    for (int i = n-2; i >=0 ; --i)
    {
        rightMin[i]=std::min(rightMin[i+1],warehouse[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        capacity[i]=std::max(leftMin[i],rightMin[i]);
    }
    std::sort(boxes.begin(),boxes.end());
    std::sort(capacity.begin(),capacity.end());

    int i=0;//pointer for boxes
    int j=0;//pointer for capacity
    int count=0;
    while (i<boxes.size() && j<capacity.size())
    {
        if (boxes[i]<=capacity[j])
        {
            i++;
            j++;
            count++;
        }
        else j++; // only increase available capacity
    }

    return count;

}