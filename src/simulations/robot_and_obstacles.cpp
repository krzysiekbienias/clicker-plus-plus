#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

struct VecHash
{
    size_t operator()(const std::vector<int>& p) const noexcept
    {
        size_t h1=std::hash<int>{}(p[0]);
        size_t h2=std::hash<int>{}(p[1]);
        return h1^(h2<<1);
    }
};

static void turnLeft(int& dx,int& dy)
{
    int oldDx=dx;
    int oldDy=dy;

    dx=-dy;
    dy=oldDx;
}


static void turnRight(int& dx,int& dy)
{
    int oldDx=dx;
    int oldDy=dy;

    dx=dy;
    dy=-oldDx;
}

int robotSim(const std::vector<int> &commands, const std::vector<std::vector<int>> &obstacles) {
    unordered_set<vector<int>,VecHash> blocked;
    for (const auto& obstacle:obstacles)
    {
        blocked.insert(obstacle);
    }
    //start robot
    int x=0;
    int y=0;

    //first move North

    int dx=0;
    int dy=1;
    int maxDistanceSquared=0;
    for (int command:commands)
    {
        if (command==-2)
        {
            turnLeft(dx,dy);
        }
        else if (command==-1)
        {
            turnRight(dx,dy);
        }
        else
        {
            for (int step = 0; step < command; ++step)
            {
                int nextX=x+dx;
                int nextY=y+dy;

                if (blocked.count({nextX,nextY}))
                {
                    break;
                }
                x=nextX;
                y=nextY;
                maxDistanceSquared=std::max(maxDistanceSquared,x*x+y*y);
            }

        }

    }
    return maxDistanceSquared;

}