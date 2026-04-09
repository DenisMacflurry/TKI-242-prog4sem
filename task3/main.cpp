#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

std::vector<int> readVector(const std::string& prompt);

int main() {
    std::vector<int> V = readVector("Введите числа через пробел: ");

    if (V.size() < 3) {
        std::cout << "Слишком мало элементов для выполнения задачи." << std::endl;
        return 0;
    }

    std::sort(V.begin(), V.end());

    auto it_start = std::upper_bound(V.begin(), V.end(), V.front());
    
    auto it_end = std::lower_bound(it_start, V.end(), V.back());

    std::cout << "Результат: ";
    if (it_start < it_end) {
        std::copy(it_start, it_end, std::ostream_iterator<int>(std::cout, " "));
    } else {
        std::cout << "[пусто - все элементы были либо min, либо max]";
    }
    std::cout << std::endl;

    return 0;
}

std::vector<int> readVector(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    return std::vector<int>(
        std::istream_iterator<int>(stream),
        std::istream_iterator<int>()
    );
}