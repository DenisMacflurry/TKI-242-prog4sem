#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main(void) {
    string name = "output.txt";
    vector<int> numbers;

    cout << "Введите числа :" << endl;

    copy(
        istream_iterator<int>(cin),
        istream_iterator<int>(),
        back_inserter(numbers)
    );

    if (numbers.empty()) {
        cerr << "Ошибка: не введено ни одного числа!" << endl;
        return 1;
    }

    ofstream outFile(name);

    if (!outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    replace_copy(
        numbers.begin(),
        numbers.end(),
        ostream_iterator<int>(outFile, "  "),
        0,
        10
    );

    outFile.close();

    cout << "Файл '" << name << "' успешно создан." << endl;

    return 0;
}