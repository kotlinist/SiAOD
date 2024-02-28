#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

int* parseInput(int argc, char *argv[]) {
    if(argc < 3) {
        cout << "Параметры m и n обязательны.";
        exit(1);
    }

    if(argc > 5) {
        cout << "Слишком много аргументов. Укажите m, n, min, max.";
        exit(1);
    }

    int args[4];
    for (int i = 1; i < argc; i++) {
        args[i-1] = stoi(argv[i]);
//        cout << args[i-1]<<"\n";
    }

    if(args[0]<1 || args[1] < 1) {
        cout << "Ожидается m > 0 и n > 0";
        exit(1);
    }

    if(argc < 5) args[3] = INT_MAX;
    if(argc == 3) args[2] = INT_MIN;

//    for(int arg : args){
//        cout << arg <<"\n";
//    }
    return args;
}

int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

vector<vector<int> > generateMatrix(int m, int n, int min, int max) {
    std::vector<std::vector<int> > matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = generateRandomNumber(min, max);
        }
    }
    return matrix;
}

void printMatrix(const vector<vector<int> > &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}