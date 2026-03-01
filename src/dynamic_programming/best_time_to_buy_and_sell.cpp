#include<std_aliases.hpp>


int maxProfitBruteForce(const std::vector<int>& prices) {
    int maxProfit=0;
    int n=prices.size();
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            int temp=prices[j]-prices[i];
            maxProfit=std::max(maxProfit,temp);
        }
    }
    return maxProfit;
}


int maxProfitSingleTransaction(const std::vector<int>& prices)
{
    int buyPrice=INT_MAX;
    int maxProfit=0;

    for ( int price:prices)
    {
        if (price<buyPrice)
        {
            buyPrice=price;
        }
        else
        {
            int profit=price-buyPrice;
            maxProfit=std::max(maxProfit,profit);
        }
    }
    return maxProfit;
}