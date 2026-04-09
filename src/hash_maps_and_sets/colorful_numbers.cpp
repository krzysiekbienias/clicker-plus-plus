#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


int colorfulNumber(int num)
{   vector<int> numbersContainer;
    std::unordered_set<long long> unique;
    while (num >0)
    {
        int ld=num%10;
        num/=10;
        numbersContainer.push_back(ld);
    }
    int n=numbersContainer.size();
    for (int i = 0; i < n; ++i)
    {  long long currentProduct=1;
        for (int j = i; j < n; ++j)
        {
            currentProduct*=numbersContainer[j];
            if (unique.count(currentProduct)) return 0;
            unique.insert(currentProduct);
        }
    }
    return 1;
}
