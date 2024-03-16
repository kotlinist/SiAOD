#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> data;

public:

    // Добавляет элемент на вершину стека
    void push(const T& element) {
        data.push_back(element);
    }

    // Удаляет и возвращает верхний элемент стека
    T pop() {
        if (data.empty()) {
            std::cout << "Стек пуст!" << std::endl;
            return T();
        }
        T element = data.back();
        data.pop_back();
        return element;
    }

    // Возвращает верхний элемент стека, не удаляя его
    T top() {
        if (data.empty()) {
            std::cout << "Стек пуст!" << std::endl;
            return T();
        }
        return data.back();
    }

    int size() {
        return data.size();
    }

    bool isEmpty() {
        return data.empty();
    }

    // Разворачивает порядок элементов в стеке
    void reverse() {
        Stack<T> tmp_stack;
        while (!isEmpty()) {
            tmp_stack.push(pop());
        }
        data = tmp_stack.data;
    }
};