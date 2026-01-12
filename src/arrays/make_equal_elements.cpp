#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

int makeElementsEqual(vector<int> &A, int B) {
    int n=A.size();
    int mod=A[0]%B;
    for (int i=1;i<n;++i){
        if(A[i]%B!=mod) return 0;
    }
    vector<int> targets={A[0]-B,A[0],A[0]+B};

    for (int target:targets){
        bool isEqualTarget=true;
        for (int i=1;i<n;++i){
            if(!(A[i]-B==target || A[i]==target || A[i]+B==target))
            {
                isEqualTarget=false;
                break;
            }
        }
        if (isEqualTarget) return 1;
    }
    return 0;
}
