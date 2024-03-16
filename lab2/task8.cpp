#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "deque.cpp"
#include "utils.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    Deque<int> deq;
    string text = read_text_from_file("lab2/task7.txt");
    stringstream ss(text);
    string num;
    vector<int> numbers;
    cout << "Исходные данные: ";
    while (ss >> num) {
        cout << num << " ";
        numbers.push_back(stoi(num));
    }

    cout << endl << "Данные после группировки: ";
    for(auto i: numbers) if(i >= 0) deq.push_back(i);
    else cout << i << " ";

    for (auto item: deq.items) cout << item << " ";

    return 0;
}