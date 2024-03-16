#include <iostream>
#include "deque.cpp"
#include "utils.cpp"

#include <stdio.h>

using namespace std;

bool check(string& code) {
    Deque<char> balance;
    for (auto c: code) {
        if(c == '[') balance.push_back(c);
        else if(c == ']') {
            if (balance.isEmpty()) return false;
            balance.pop_back();
        }
    }
    return balance.isEmpty();
}

int main(int argc, char *argv[]) {
    string code = read_text_from_file("lab2/task5.txt");
    cout << code;
    if (check(code)) cout << "✅ Баланс скобок соблюден";
    else cout << "❌ Баланс скобок НЕ соблюден";
    return 0;
}