#include <iostream>
#include <vector>
#include "utils.cpp"

void shellSort(vector<int> &arr, int N) {
    for (int gap = N/2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i += 1) {
            //сортировка подсписков, созданных с помощью gap
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
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
        shellSort(row, row.size());
    }

    cout << endl << "Матрица после сортировки ее строк:" << endl;
    printMatrix(matrix);

    return 0;
}