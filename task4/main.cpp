#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

struct point {
    int x, y;
    string s;

    bool operator<(const point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

istream& operator>>(istream& is, point& p) {
    return is >> p.x >> p.y >> p.s;
}

ostream& operator<<(ostream& os, const point& p) {
    return os << p.x << " " << p.y << " " << p.s;
}

int main() {
    string name = "points.txt";
    
    ifstream input(name);
    if (!input) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    vector<point> V((istream_iterator<point>(input)), istream_iterator<point>());
    input.close();

    point zero_point = {0, 0, ""};

    using namespace std::placeholders;
    stable_partition(V.begin(), V.end(), 
        bind(less<point>(), _1, zero_point)
    );

    cout << "Преобразованный набор точек:" << endl;
    copy(V.begin(), V.end(), ostream_iterator<point>(cout, "\n"));

    return 0;
}