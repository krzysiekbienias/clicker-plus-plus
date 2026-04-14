#include <std_aliases.hpp>

using namespace stl;
using namespace io;
using namespace str;

static void rotate90ccw(int& dx,int& dy)
{
    int oldDx=dx;
    int oldDy=dy;

    dx=-dy;
    dy=oldDx;
}

std::vector<std::vector<int>> clockwiseGridOdyssey(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> res;
    res.reserve(rows*cols);
    int r=rStart;
    int c=cStart;
    //we start moving east
    int dx=1;
    int dy=0;
    int jump=1;
    bool extend=false;

    while (res.size() < rows * cols) {

        // Robimy dokładnie 'jump' kroków w aktualnym kierunku (dx, dy)
        for (int k = 0; k < jump; ++k) {

            // 1. Sprawdzamy czy aktualne (r, c) jest na planszy.
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                res.push_back({r, c});
            }

            // 2. Robimy JEDEN mały krok w wyznaczonym kierunku.
            // Żadnego mnożenia! Po prostu dodajemy kierunek do pozycji.
            c = c + dx;
            r = r + dy;
        }

        // Dopiero gdy zrobiliśmy wszystkie kroki z 'jump',
        // obracamy się w miejscu.
        rotate90ccw(dx, dy);

        // Aktualizujemy logikę wydłużania kroku - tu miałeś wszystko dobrze!
        if (extend) {
            jump++;
        }
        extend = !extend;
    }
    return res;
}
