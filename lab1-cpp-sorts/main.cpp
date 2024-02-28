#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.cpp"

int main(int argc, char *argv[]) {
    string alg = argv[1];
    int* args = parseInput(argc, argv);
    int m = args[0];
    int n = args[1];
    int min = args[2];
    int max = args[3];

    vector<vector<int> > matrix = generateMatrix(m, n, min, max);
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    for(auto &row: matrix) {
        sort(row.begin(), row.end());
    }

    cout << endl << "Матрица после сортировки ее строк:" << endl;
    printMatrix(matrix);

    return 0;
}