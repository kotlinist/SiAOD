#include <iostream>
#include <vector>
#include "utils.cpp"
#include <sstream>

using namespace std;

int binarySearch(vector<int> &data, int target) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (data[middle] == target) {
            return middle;
        } else if (data[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

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

    int index = binarySearch(vec, target);

    if (index == -1) {
        cout << "Элемент не найден" << endl;
    } else {
        cout << "Элемент найден по индексу " << index << endl;
    }

    return 0;
}
