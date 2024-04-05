#include <iostream>
#include <vector>
#include <sstream>
#include "utils.cpp"

using namespace std;

int fibonacciSearch(const std::vector<int>& arr, int target) {
    int fib2 = 0; // n-2 число Фибоначчи
    int fib1 = 1; // n-1 число Фибоначчи
    int fib = fib2 + fib1; // текущее число Фибоначчи

    while (fib < arr.size()) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1; // смещение от начала массива

    while (fib > 1) {
        int i = std::min(offset + fib2, static_cast<int>(arr.size()) - 1);
        if (arr[i] < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > target) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }
    if (fib1 == 1 && arr[offset + 1] == target) return offset + 1;
    return -1;
}

int main(int argc, char *argv[]) {
    vector<int> vec;
    int target;
    if(argc==2) {
        string input = read_text_from_file("vec.txt");
        stringstream ss(input);
        string num;
        while (ss >> num) {
            vec.push_back(stoi(num));
        }
        target = stoi(argv[1]);

    } else if(argc==4) {
        int n = stoi(argv[1]);
        int min = stoi(argv[2]);
        int max = stoi(argv[3]);
        vec = generateVector(n, min, max);
        vec.push_back(777);
        sort(vec.begin(), vec.end());
        for (auto el: vec) cout << el << " ";
        cout << endl;

        cout << "Число для удаления: ";
        int del;
        cin >> del;
        for (size_t i=0; i<vec.size(); i++) {
            if (vec[i] == del) {
                del = i;
                break;
            }
        }
        if(del < vec.size()) vec.erase(vec.begin() + del);
        for (auto el: vec) cout << el << " ";
        cout << endl;

        cout << "Число для поиска: ";
        cin >> target;
    } else{
        exit(1);
    }

    int index = fibonacciSearch(vec, target);

    if (index == -1) {
        cout << "Элемент не найден" << endl;
    } else {
        cout << "Элемент найден в индексе " << index << endl;
    }

    return 0;
}
