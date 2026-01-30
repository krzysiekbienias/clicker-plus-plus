#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

// Implement your logic here.

long long fillingJarsBF(int n, vector<vector<int>> operations) {

    long long vectSum=0;
    vector<long long>vec(n,0);

    for (vector<int> v: operations)
    {   int a=v[0];
        int b=v[1];
        int k=v[2];
        for (int i = a-1; i < b; ++i)
        {
            vec[i]+=k;
        }
    }
    vectSum=std::accumulate(vec.begin(),vec.end(),0LL);
    double av=vectSum/n;
    long long res=floor(av);
    return res;

}



long long  fillingJars(int n, std::vector<std::vector<int>> operations)
{
    vector<long long> diff(n+1,0);
    for (const auto &op:operations)
    {
        int a=op[0]-1;
        int b=op[1];
        long long k=op[2];
        diff[a]+=k;
        diff[b]-=k;

    }
    long long running=0;
    long long total=0;
    for (int i = 0; i < n; ++i)
    {
        running+=diff[i];
        total+=running;
    }
    long long res=floor(total/n);
    return res;
}