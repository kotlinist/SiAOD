#include <iostream>
#include <vector>
#include <sstream>
#include "utils.cpp"

using namespace std;

int main(int argc, char *argv[]) {

    int n = stoi(argv[1]);
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);

    vector<int> vec;
    for (size_t i = 0; i < n; ++i)
        vec.push_back(generateRandomNumber(min, max));

    sort(vec.begin(), vec.end());

    std::ofstream output("vec.txt");
    if (output.is_open()) {
        for (auto el: vec) {
            output << el << " ";
            cout << el << " ";
        }
        cout << endl;
        output.close();
    } else {
        std::cout << "Не удалось открыть файл для записи" << std::endl;
        exit(1);
    }

    return 0;
}