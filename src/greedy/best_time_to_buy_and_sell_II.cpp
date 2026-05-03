#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;


int maxProfitMultipleTrans(const std::vector<int>& prices){
    int res=0;
    for (int i = 1; i < static_cast<int>(prices.size()); i++) {
        if (prices[i-1]<prices[i]) {
        res+=prices[i]-prices[i-1];
        }
    }
    return res;

}