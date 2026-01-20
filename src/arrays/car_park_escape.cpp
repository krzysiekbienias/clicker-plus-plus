#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

static pair<int, int> carPosition(const std::vector<std::vector<int>>& carpark)
{
    int r = -1;
    int c = -1;
    if (!carpark.empty())
    {
        r = carpark.size();
        c = carpark[0].size();
    }


    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (carpark[i][j] == 2)
            {
                return {i, j};
            }
        }
    }
    throw std::invalid_argument("There is no car");
}

static int stairsPosition(const vector<int>& row)
{
    int n = row.size();
    for (int i = 0; i < n; ++i)
    {
        if (row[i] == 1)
        {
            return i;
        }
    }
    return -1;
}

// Implement your logic here.


std::vector<std::string> escape(const std::vector<std::vector<int>>& carpark)
{   vector<string> res;
    int lastRow=static_cast<int>(carpark.size())-1; //ground floor
    int exitCol=static_cast<int>(carpark[lastRow].size())-1; // last col

    auto carLocation=carPosition(carpark);
    int carRow=carLocation.first;
    int carCol=carLocation.second;
    //car is already on ground floor
    if (carRow==lastRow)
    {
        int toExit=exitCol-carCol;
        if (toExit>0)
        {
             res.push_back("R"+std::to_string(toExit));
        }
        return res;
    }
    while (carRow<lastRow)
    {
        int stairCol=stairsPosition(carpark[carRow]);
        if (stairCol==-1)
        {//should not happen
            return res;
        }
        //move to the stairs
        int diff=stairCol-carCol;
        if (diff<0)
        {
            res.push_back("L"+std::to_string(-diff));
        }
        else if (diff>0)
        
        {
                res.push_back("R"+std::to_string(diff));
        }
        carCol=stairCol;
        int moveDown=0;
        while (carRow<lastRow)
        {
            //while becasue we are trying to move down untill we can using stairs
            
            moveDown++;
            carRow++;

            if (carRow==lastRow) break; // we hit the ground
            //it may also happen that stairs in the next row is in another column
            int nextStair=stairsPosition(carpark[carRow]);
            if (nextStair!=carCol) break;
        }
        if (moveDown>0) res.push_back("D"+std::to_string(moveDown));
    }
    //we reach to the ground floor
    int toExit=exitCol-carCol;
    if (toExit>0)
    {
        res.push_back("R"+std::to_string(toExit));
    }


    return res;

}