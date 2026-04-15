#include <vector>


static void shiftAndUpdate(std::vector<int> &array,int num,int idx)
{
    for (int i = 0; i <=idx; ++i)
    {
        if (i==idx)
        {
            array[i]=num;
        }
        else
        {
            array[i]=array[i+1];
        }
    }
}


static void updateLargest(std::vector<int> &threeLargest,int num)
{
    if (num>threeLargest[2])
    {
        shiftAndUpdate(threeLargest,num,2);
    }
    else if (num>threeLargest[1])
    {
        shiftAndUpdate(threeLargest,num,1);
    }
    else if (num>threeLargest[0])
    {
        shiftAndUpdate(threeLargest,num,0);
    }
}


std::vector<int> findThreeLargestNumbers(std::vector<int>& array) {
    std::vector<int> threeLargest={INT_MIN,INT_MIN,INT_MIN};
    for (int num:array)
    {
        updateLargest(threeLargest,num);
    }
    return threeLargest;
}