#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 8;
int solutionsCount = 0;

// Функция для проверки, находится ли клетка под атакой ферзей
bool isSafe(int row, int col, vector<int> position) {
    for (int i = 0; i < row; ++i) {
        if (position[i] == col || // Проверка на столбец
            position[i] - i == col - row || // Проверка на главную диагональ
            position[i] + i == col + row) // Проверка на побочную диагональ
            return false;
    }
    return true;
}

// Рекурсивная функция для размещения ферзей на доске
void solve(int row, vector<int> position) {
    if (row == SIZE) {
        ++solutionsCount;
        cout << "Решение " << solutionsCount << ":\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (position[i] == j)
                    cout << "🔴  ";
                else
                    cout << "⬜️️  ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int col = 0; col < SIZE; ++col) {
        if (isSafe(row, col, position)) {
            position[row] = col;
            solve(row + 1, position);
        }
    }
}

int main() {
    vector<int> position(SIZE);
    solve(0, position);
    cout << "Всего решений: " << solutionsCount << "\n";
    return 0;
}

//Эта программа решает задачу о восьми ферзях, используя рекурсивный подход. Она пытается разместить ферзя в каждой колонке каждого ряда и проверяет, находится ли клетка под атакой других ферзей. Если клетка безопасна, программа продолжает размещение следующего ферзя. Когда ферзи размещены во всех восьми рядах, программа выводит решение на экран. В конце работы программа также выводит общее количество найденных решений.