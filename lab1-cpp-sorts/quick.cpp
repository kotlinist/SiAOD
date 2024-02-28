#include <iostream>
#include <vector>
#include "utils.cpp"

int partition(vector<int>& values, int l, int r) {
    int x = values[r];
    int less = l;

    for (int i = l; i < r; ++i) {
        if (values[i] <= x) {
            swap(values[i], values[less]);
            ++less;
        }
    }
    swap(values[less], values[r]);
    return less;
}

void quickSortImpl(vector<int>& values, int l, int r) {
    if (l < r) {
        int q = partition(values, l, r);
        quickSortImpl(values, l, q - 1);
        quickSortImpl(values, q + 1, r);
    }
}

void quickSort(vector<int>& values) {
    if (!values.empty()) {
        quickSortImpl(values, 0, values.size() - 1);
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
        quickSort(row);
    }

    cout << endl << "Матрица после сортировки ее строк:" << endl;
    printMatrix(matrix);

    return 0;
}