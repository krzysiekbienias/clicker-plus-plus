#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

std::vector<std::string> findRepeatedDnaSequences(std::string s)
{
    std::vector<std::string> result;
    //edge case if string is smaller than 10
    if (s.length()<10)
    {
        return result;
    }
    int n=s.length();
    int mapDNA[128]={0};
    mapDNA['A']=0;//00
    mapDNA['C']=1;//01
    mapDNA['G']=2;//10
    mapDNA['T']=3;//11

    unordered_map<int, int> counts;
    int hash=0;
    const int mask=(1<<20)-1; //20 bits range '111...11'
    //std::bitset<31> binMask(mask);
    for (int i = 0; i < n; ++i)
    {
        hash=((hash<<2)|mapDNA[s[i]])&mask;
        //std::bitset<31> bin(hash);
        // cout<<"mask: "<<mask<<" bin representation "<<binMask<<'\n';
        // cout<<"hash: "<<hash<<" bin hash "<<bin<<'\n';
        if (i>=9)
        {
            counts[hash]++;

        }
        if (counts[hash]==2)
        {
            result.push_back(s.substr(i-9,10));
        }

    }
    return result;
}
