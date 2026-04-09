#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main(void) {
    string name = "output.txt";
    vector<int> numbers = {1, 0, 5, 0, 12, 3, 0, 7};

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