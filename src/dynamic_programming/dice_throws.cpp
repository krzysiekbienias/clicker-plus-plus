#include <std_aliases.hpp>

#include "utils/print_utils.hpp"
#include "matrix/row_by_row.hpp"
using namespace stl;

int diceThrows(int numDice, int numSides, int target) {
    if (numDice<=0 || numSides<=0||target <=0) return 0;
    int rows=numDice+1; //+1 because we want to consider also zero Dice.
    int cols=target+1;
    VVI dp(rows,VI(cols,0));
    //dp[i][j] nb of ways to get sum j having i dieces
    dp[0][0]=1; //no dices there is one way to get sum=0 just not throw.
    //dp[0][*]=0 because with no deices you cannot get positive sum.
    //dp[1][*]=1 but not for dp[1][0] and dp[1][cols]

    for (int j =1;j<=target && j<=numSides;++j) {
        dp[1][j]=1;
    }
    //DEBUG
    //rowByRowPrint(dp);
    for (int i=2;i<rows;++i) {
        for (int j=0;j<cols;++j) {
            int ways=0;
            for (int f=1;f<=numSides;++f) {
                if (j<f) break;
                ways+=dp[i-1][j-f];
            }
        dp[i][j]=ways;
        }
    }
    //DEBUG
    //rowByRowPrint(dp);

    return dp[rows-1][cols-1];
}