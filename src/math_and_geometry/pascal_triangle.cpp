#include <std_aliases.hpp>
using namespace stl;

vector<vector<int> > generatePascalTriangle(int numRows) {
    if (numRows == 0) return {};
    vector<vector<int> > pt;
    //pierwszy wiersz sklada sie tylko z {{1}}
    pt.push_back({1});
    for (int i = 1; i < numRows; ++i) {
        // potrzebujemy poprzedni wiersz bo to building block dla kolejnego
        //moze byc const bo nie bedziemy go zmieniac tylko jako punkt odniesienia
        const vector<int> &prev = pt.back();
        //kotener na nowy wiersz
        vector<int> row(i + 1);
        row[0] = 1;
        row[i] = 1;
        for (int j = 1; j < i; ++j) {
            row[j] = prev[j - 1] + prev[j];
        }
        pt.push_back(std::move(row));
    }
    return pt;
}
