#include <iostream>
#include <vector>
#include "utils.cpp"

void insertionSort(vector<int> &arr) {
    for(size_t i = 1; i < arr.size(); ++i) {
        int el = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > el) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = el;
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
        insertionSort(row);
    }

    cout << endl << "Матрица после сортировки ее строк:" << endl;
    printMatrix(matrix);

    return 0;
}