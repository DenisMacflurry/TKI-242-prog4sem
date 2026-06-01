#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename Container>
void inputContainer(Container& container, const string& prompt) {
    cout << prompt << endl;
    copy(
        istream_iterator<int>(cin),
        istream_iterator<int>(),
        back_inserter(container)
    );
    cin.clear();
    cin.ignore();
}

template<typename Container>
bool checkEmpty(const Container& container, const string& containerName) {
    if (container.empty()) {
        cout << "Ошибка: " << containerName << " пуст!" << endl;
        return true;
    }
    return false;
}

template<typename Container>
void outputContainer(const Container& container, const string& containerName) {
    cout << containerName << ": ";
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}

int main(void) {
    vector<int> V;
    list<int> L;

    inputContainer(V, "Введите элементы вектора:");

    inputContainer(L, "Введите элементы списка:");

    if (checkEmpty(V, "Вектор")) {
        return 1;
    }

    if (checkEmpty(L, "Список")) {
        return 1;
    }

    auto list_it = next(L.begin(), min(5, (int)L.size()));
    L.insert(list_it, V.rend() - min(5, (int)V.size()), V.rend());

    outputContainer(V, "Вектор");
    outputContainer(L, "Итоговый список");
    
    return 0;
}
