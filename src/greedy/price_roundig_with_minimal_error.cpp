#include <std_aliases.hpp>
#include <sstream>
#include <iomanip>

using namespace stl;
using namespace io;
using namespace str;

static std::pair<int,int> parseStringToCeilAndFloor(std::string price)
{
    int dotPos=price.find('.');
    int intPart=std::stoi(price.substr(0,dotPos));
    int fracPart=std::stoi(price.substr(dotPos+1));

    int fl=intPart;
    int cl=intPart+(fracPart>0); //frac>0 return bool that's 1 if true
    return {fl,cl};
}

static int getFraction(std::string price)
{
    int dotPos=price.find('.');
    int fracPart=std::stoi(price.substr(dotPos+1));
    return fracPart;
}


std::string roundingWithMinimalError(const std::vector<std::string> &prices, int target) {
    int n=prices.size();
    int res=0;
    int minSum=0;
    int maxSum=0;
    for (int i = 0; i < n; ++i)
    {
        minSum+=parseStringToCeilAndFloor(prices[i]).first;
        maxSum+=parseStringToCeilAndFloor(prices[i]).second;
    }
    //feasability
    if (target<minSum||target>maxSum)
    {
        return "-1";
    }
    //how many should be replaced ceil intead
    int needCeil=target-minSum;

    std::vector<pair<int,std::string>> candidates;

    for (const string& price:prices)
    {
        int frac=getFraction(price);
        if (frac>0)
        {
            candidates.push_back({frac,price});
        }

    }

    std::sort(candidates.begin(), candidates.end(),
              [](const auto& a, const auto& b)
              {
                  return a.first > b.first;
              });// Sort candidates by fractional part in descending order
    for (int i = 0; i < candidates.size(); ++i)
    {
        int frac=candidates[i].first;
        if (i<needCeil)
        {
            res+=(1000-frac);//ceil
        }
        else
        {
            res+=frac;//
        }

    }
    int integerPart=res/1000;
    int fractionalPart=res%1000;

    std::ostringstream oss;
    oss<<integerPart<<'.'<<std::setprecision(3)<<std::setfill('0')<<fractionalPart;

    return oss.str();

}
