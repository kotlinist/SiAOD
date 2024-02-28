#include <iostream>
#include <vector>
#include "utils.cpp"

void selectionSort(vector<int>& arr) {
    for (auto i = arr.begin(); i != arr.end(); ++i) {
        auto j = std::min_element(i, arr.end());
        swap(*i, *j);
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
        selectionSort(row);
    }

    cout << endl << "Матрица после сортировки ее строк:" << endl;
    printMatrix(matrix);

    return 0;
}