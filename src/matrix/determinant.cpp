#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

bool checkPivot(vector<vector<double>>& matrix, int& swapsCounter, int k)
{
    std::size_t nbOfRows = matrix.size();
    if (matrix[k][k] != 0)
    {
        return true;
    }
    for (int r = k + 1; r < nbOfRows; ++r)
    {
        if (matrix[r][k] == 0)
            continue;
        swapsCounter++;
        std::swap(matrix[r], matrix[k]);
        return true;
    }
    return false;
}

//dismiss becasue is not prepared for integer elements
int determinant(std::vector<std::vector<int>>& matrix)
{
    int nbOfSwaps = 0;
    int sign = 1;
    std::size_t nbOfRows = matrix.size();
    std::size_t nbOfCols = matrix[0].size();

    vector<vector<double>> upperTriangle(nbOfRows, vector<double>(nbOfCols, 0));
    for (int n = 0; n < nbOfRows; ++n)
    {
        std::transform(matrix[n].begin(), matrix[n].end(),
                       upperTriangle[n].begin(), [](int x) { return static_cast<double>(x); });
    }

    for (int c = 0; c < nbOfCols; ++c)
    {
        if (!checkPivot(upperTriangle, nbOfSwaps, c))
            return 0;
        double pivot = upperTriangle[c][c];
        //pivot row is cop to upper

        for (int r = c + 1; r < nbOfRows; ++r)
        {
            double mult = upperTriangle[r][c] / pivot;
            for (int i = c; i < nbOfCols; ++i)
            {
                upperTriangle[r][i] = upperTriangle[r][i] - mult * upperTriangle[c][i];
            }
        }
    }
    int diagonalProduct = 1;
    if (nbOfSwaps % 2 != 0)
        sign = -1;
    for (int i = 0; i < nbOfCols; ++i)
    {
        diagonalProduct *= upperTriangle[i][i];
    }
    return sign * diagonalProduct;
}


bool checkPivotBareiss(vector<vector<long long>>& matrix, int& swapsCounter, int k)
{
    std::size_t nbOfRows = matrix.size();
    if (matrix[k][k] != 0)
    {
        return true;
    }
    for (int r = k + 1; r < nbOfRows; ++r)
    {
        if (matrix[r][k] == 0)
            continue;
        swapsCounter++;
        std::swap(matrix[r], matrix[k]);
        return true;
    }
    return false;
}

int determinantBareiss(vector<vector<long long>>& matrix)
{
    int nbOfRows=matrix.size();
    int nbOfCols = matrix[0].size();
    if (nbOfRows!=nbOfCols)
    {
        throw std::invalid_argument("We may only calculate determinant from square matrix.");
    }
    auto current = matrix;
    auto next = matrix;
    int nbOfSwaps = 0;
    int prevPivot = 1;
    for (int k = 0; k < nbOfCols; ++k)

    {
        if (!checkPivotBareiss(current, nbOfSwaps, k))
            return 0;
        int pivot  = current[k][k];
        for (int r = k + 1; r < nbOfCols; ++r)
        {   next[r][k]=0;
            for (int j = k + 1; j < nbOfCols; ++j)
            {
                int lu = current[k][k];
                int bu = current[r][k];
                int ur = current[k][j];
                int br = current[r][j];

                long long minorValue = (lu * br - ur * bu)/prevPivot;
                next[r][j] = minorValue;
            }
        }
    prevPivot=pivot;
    current=next;
    }
    int sign=1;
    if (nbOfSwaps%2!=0)
    {
        sign=-1;
    }
    return sign*next[nbOfRows-1][nbOfCols-1];
}
