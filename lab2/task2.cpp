#include <iostream>
#include <vector>
#include <fstream>
#include "deque.cpp"

using namespace std;

// Отсортировать строки файла, содержащие названия книг, в алфавитном порядке с использованием двух деков.

int main(int argc, char *argv[]) {
    Deque<string> deq;
    Deque<string> sort_deq;

    // Заполняем дек
    std::ifstream file("lab2/task1_books.txt");
    if (!file.is_open()) {
        std::cerr << "Файл не найден!" << std::endl;
        std::exit(1);
    }
    cout << "Список книг до сортировки:" << endl;
    string line;
    while (std::getline(file, line)) {
        deq.push_back(line);
        cout << line << endl;
    }
    file.close();

    while(!deq.isEmpty()) {
        string el = deq.pop_back();
        // пока sort_deq не пустой и element меньше чем последний в sort_deq
        while(!sort_deq.isEmpty() && el < sort_deq.peek()) {
            // добавляем в deq последний элемент sort_deq
            deq.push_back(sort_deq.pop_back());
        }
        sort_deq.push_back(el);
    }

    cout << endl << "Список книг после сортировки:" << endl;
    while(!sort_deq.isEmpty())
        cout << sort_deq.pop_front() << endl;

    return 0;
}