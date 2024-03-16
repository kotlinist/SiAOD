#include <iostream>
#include "stack.cpp"
#include "utils.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    Stack<char> stack;
    string result;
    string text = read_text_from_file("lab2/task6.txt");

    cout << "Исходная строка: " << text;

    for (auto c: text) {
        // добавление в строку чисел иначе в стек
        if(isdigit(c)) result += c;
        else stack.push(c);

    }

    // добавление в строку букв
    for (auto item: stack.items)
        if(isalpha(item)) result += item;
    // добавление в строку остальных символов
    for (auto item: stack.items)
        if(!isalpha(item)) result += item;

    cout << "Строка после группировки: " << result;

    return 0;
}