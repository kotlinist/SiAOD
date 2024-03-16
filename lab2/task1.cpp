#include <iostream>
#include <vector>
#include "stack.cpp"
#include "deque.cpp"

using namespace std;

//template <typename T>
//class Stack {
//private:
//    vector<T> elements;
//
//public:
//    // Добавляет элемент на вершину стека
//    void push(const T& element) {
//        elements.push_back(element);
//    }
//
//    // Удаляет и возвращает верхний элемент стека
//    T pop() {
//        if (elements.empty()) {
//            throw runtime_error("Stack is empty");
//        }
//        T element = elements.back();
//        elements.pop_back();
//        return element;
//    }
//
//    // Возвращает верхний элемент стека, не удаляя его
//    T peek() const {
//        if (elements.empty()) {
//            throw runtime_error("Stack is empty");
//        }
//        return elements.back();
//    }
//
//    // Разворачивает порядок элементов в стеке
//    void reverse() {
//        vector<T> reversed_elements;
//        while (!elements.empty()) {
//            reversed_elements.push_back(elements.back());
//            elements.pop_back();
//        }
//        elements = reversed_elements;
//    }
//};
//
//template <typename T>
//class Deque {
//public:
//    Deque() : front(0), back(0) {}
//
//    // Добавление элемента в начало
//    void push_front(const T& value) {
//        if (front == 0) {
//            data.push_back(value);
//            back++;
//        } else {
//            data.insert(data.begin() + front - 1, value);
//            front++;
//            back++;
//        }
//    }
//
//    // Добавление элемента в конец
//    void push_back(const T& value) {
//        data.push_back(value);
//        back++;
//    }
//
//    // Удаление элемента из начала
//    void pop_front() {
//        if (front == 0) {
//            data.erase(data.begin());
//            back--;
//        } else {
//            front--;
//            data.erase(data.begin() + front);
//        }
//    }
//
//    // Удаление элемента из конца
//    void pop_back() {
//        data.pop_back();
//        back--;
//    }
//
//    // Получение элемента из начала
//    T front() const {
//        return data[front];
//    }
//
//    // Получение элемента из конца
//    T back() const {
//        return data[back - 1];
//    }
//
//    // Размер дека
//    size_t size() const {
//        return back - front;
//    }
//
//    // Пуст ли дек
//    bool empty() const {
//        return size() == 0;
//    }
//
//    // Реверс дека
//    void reverse() {
//        for (size_t i = 0; i < size() / 2; i++) {
//            swap(data[front + i], data[back - 1 - i]);
//        }
//    }
//
//private:
//    vector<T> data;
//    size_t front;
//    size_t back;
//};



int main(int argc, char *argv[]) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);

    int topElement = stack.top();
    std::cout << "Элемент на вершине стека: " << topElement << std::endl;

    stack.reverse();

    cout << stack.size() << endl;

    int removedElement = stack.pop();
    std::cout << "Извлечен элемент: " << removedElement << std::endl;

    int removedElement2 = stack.pop();
    std::cout << "Извлечен элемент: " << removedElement2 << std::endl;

    if (stack.isEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
    }


//    int* args = parseInput(argc, argv);
//    int m = args[0];
//    int n = args[1];
//    int min = args[2];
//    int max = args[3];
//
//    vector<vector<int> > matrix = generateMatrix(m, n, min, max);
//    cout << "Исходная матрица:" << endl;
//    printMatrix(matrix);
//
//    for(auto &row: matrix) {
//        bubbleSort(row);
//    }
//
//    cout << endl << "Матрица после сортировки ее строк:" << endl;
//    printMatrix(matrix);

    return 0;
}