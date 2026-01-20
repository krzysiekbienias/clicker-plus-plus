#include "std_aliases.hpp"

#include "arrays/fruit_machine.hpp"
using namespace stl;
using namespace io;
using namespace str;




unsigned fruit(const array<vector<string>, 3> &reels, const array<unsigned, 3> &spins)
{
    unordered_map<symbol,int> spinPoints={
        {symbol::wild,100},
        {symbol::star,90},
    {symbol::bell,80},
        {symbol::shell,70},
        {symbol::seven,60},
        {symbol::cherry,50},
        {symbol::bar,40},
        {symbol::king,30},
        {symbol::queen,20},
        {symbol::jack,10}
    };
    //take symbol from each reel
    symbol a=parseSymbol(reels[0][spins[0]]);
    symbol b=parseSymbol(reels[1][spins[1]]);
    symbol c=parseSymbol(reels[2][spins[2]]);

    unordered_map<symbol,int> cnt;
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;

    if (cnt.size()==1){//3 identical symbols
        return static_cast<unsigned>(spinPoints[a]);
    }
    if (cnt.size()==3)
    {//each symbol is different
        return 0;
    }
    //cnt.size()==2 -->{2,1} set
    //two interesting cases, 1 when 2 Wilds and 1 Wild occur.
    symbol pairSym=symbol::wild;
    symbol singleSym=symbol::wild;
    //assign which is pair symbol and which is single symbol
    for (auto&[sym,val]:cnt)
    {
        if (val==2) pairSym=sym;
        else singleSym=sym;
    }
    if (pairSym==symbol::wild)
    {
        return 10;
    }
    unsigned base=static_cast<unsigned>(spinPoints[pairSym]/10);
    if (singleSym==symbol::wild)
        base*=2;
    return base;

}