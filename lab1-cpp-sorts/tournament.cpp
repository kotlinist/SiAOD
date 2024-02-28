#include <iostream>
#include <vector>
#include "utils.cpp"
#include <algorithm>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, vector<int> &temp, vector<int> &indexArray) {
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            indexArray[k] = i;
            i++;
        } else {
            temp[k] = arr[j];
            indexArray[k] = j;
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        indexArray[k] = i;
        i++;
        k++;
    }
    for (k = low; k <= high; k++) {
        arr[k] = temp[k];
    }
}

void sortUtil(std::vector<int>& arr, int low, int high, std::vector<int>& temp, std::vector<int>& indexArray) {
    if (low < high) {
        int mid = (low + high) / 2;
        sortUtil(arr, low, mid, temp, indexArray);
        sortUtil(arr, mid + 1, high, temp, indexArray);
        merge(arr, low, mid, high, temp, indexArray);
    }
}

void tournamentSort(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        temp[i] = arr[i];
    }
    std::vector<int> indexArray(n);
    for (int i = 0; i < n; i++) {
        indexArray[i] = i;
    }
    sortUtil(arr, 0, n - 1, temp, indexArray);
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
        tournamentSort(row);
    }

    cout << endl << "Матрица после сортировки ее строк:" << endl;
    printMatrix(matrix);

    return 0;
}