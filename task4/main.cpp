#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

/**
 * @brief Структура для представления точки с координатами и строкой
 * @param x Координата X
 * @param y Координата Y
 * @param s Строка, связанная с точкой
 */
struct point {
    int x, y;
    string s;

    bool operator<(const point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

/**
 * @brief Перегрузка оператора ввода для структуры point
 * @param is Поток ввода
 * @param p Точка, в которую будут считаны данные
 * @return Поток ввода после чтения данных
 */
istream& operator>>(istream& is, point& p) {
    return is >> p.x >> p.y >> p.s;
}

/**
 * @brief Перегрузка оператора вывода для структуры point
 * @param os Поток вывода 
 * @param p Точка, данные которой будут выведены
 * @return Поток вывода после записи данных
 */
ostream& operator<<(ostream& os, const point& p) {
    return os << p.x << " " << p.y << " " << p.s;
}

/**
 * @brief Точка входа в программу
 * @return Возвращает 0 при успешном завершении
 */
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