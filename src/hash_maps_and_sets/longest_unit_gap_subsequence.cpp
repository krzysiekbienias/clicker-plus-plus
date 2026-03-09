#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

int findLHS(std::vector<int>& nums) {
   unordered_map<int,int> freq;
   for (int x:nums)
   {
      freq[x]++;
   }
   int maximum=0;
   for (const auto & [value,count]:freq)
   {
      auto it =freq.find(value+1);
      if (it!=freq.end())
      {
         maximum=std::max(maximum,count+it->second);
      }
   }
   return maximum;
}
