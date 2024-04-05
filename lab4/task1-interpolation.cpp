#include <iostream>
#include <vector>
#include "utils.cpp"
#include <sstream>

using namespace std;

int interpolationSearch(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x)
                return low;
            return -1;
        }

        // Формула для интерполяции
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        // Если x меньше значения в pos, продолжаем поиск в левой части
        if (arr[pos] > x)
            high = pos - 1;
            // Если x больше значения в pos, продолжаем поиск в правой части
        else if (arr[pos] < x)
            low = pos + 1;
            // Если значение в pos равно x, то мы нашли элемент
        else
            return pos;
    }
    return -1; // Элемент не найден
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

    int index = interpolationSearch(vec, target);

    if (index == -1) {
        cout << "Элемент не найден" << endl;
    } else {
        cout << "Элемент найден в индексе " << index << endl;
    }

    return 0;
}
