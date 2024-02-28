#include <iostream>
#include <vector>
#include "utils.cpp"

void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); ++i) {
        for (size_t j = 0; j + 1 < arr.size() - i; ++j) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int* args = parseInput(argc, argv);
    int m = args[0];
    int n = args[1];
    int min = args[2];
    int max = args[3];

    vector<vector<int> > matrix = generateMatrix(m, n, min, max);
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    for(auto &row: matrix) {
        bubbleSort(row);
    }

    cout << endl << "Матрица после сортировки ее строк:" << endl;
    printMatrix(matrix);

    return 0;
}