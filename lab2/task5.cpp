#include <iostream>
#include "stack.cpp"
#include "utils.cpp"

#include <stdio.h>

using namespace std;

bool check(string& code) {
    Stack<char> balance;
    for (auto c: code) {
        if(c == '(') balance.push(c);
        else if(c == ')') {
            if (balance.isEmpty()) return false;
            balance.pop();
        }
    }
    return balance.isEmpty();
}

int main(int argc, char *argv[]) {
    string code = read_text_from_file("lab2/task4.txt");
    cout << code;
    bool res = check(code);
    if (res) cout << "T";
    else cout << "F";
    return 0;
}