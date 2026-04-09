#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    vector<int> V = {10, 20, 30, 40, 50, 60, 70};
    list<int> L = {1, 2, 3, 4, 5, 6, 7, 8};

    auto list_it = next(L.begin(), 5);
    L.insert(list_it, V.rend() - 5, V.rend());

    cout << "Итоговый список: ";
    for (int x : L) cout << x << " ";
    
    return 0;
}