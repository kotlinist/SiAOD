#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;

string to_lower(string s) {
    for(char &c : s)
        c = tolower(c);
    return s;
}

std::vector<int> badCharHeuristic(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> badChar(256, -1); // ASCII characters

    // Заполнение таблицы сдвигов
    for (int i = 0; i < m; ++i) {
        badChar[pattern[i]] = i;
    }

    return badChar;
}

std::vector<int> searchBoyerMoore(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrences;
    int n = text.size();
    int m = pattern.size();
    std::vector<int> badChar = badCharHeuristic(pattern);

    int s = 0; // Индекс начала текущего сравнения в тексте
    while (s <= n - m) {
        int j = m - 1;

        // Сравнение шаблона с текстом справа налево
        while (j >= 0 && pattern[j] == text[s + j]) {
            --j;
        }

        if (j < 0) { // Найдено совпадение
            occurrences.push_back(s);
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else { // Несовпадение
            s += std::max(1, j - badChar[text[s + j]]);
        }
    }

    return occurrences;
}

int main(int argc, char *argv[]) {
    bool IGNORE_REGISTER = false;

    if(argc < 3 || argc > 4) {
        cout << "Использование:\nbm -i target string\n target - искомая подстрока\n stirng - строка, в которой производится поиск\n -i - игнорировать регистр";
        exit(1);
    }

    for(size_t i = 0; i < argc; i++)
        if(strcmp(argv[i], "-i") == 0) IGNORE_REGISTER = true;

    string str = argv[argc-1];
    string pattern = argv[argc-2];
    if(IGNORE_REGISTER) {
        cout << "Ignore register\n";
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
    }

    std::vector<int> occurrences = searchBoyerMoore(str, pattern);

    std::cout << "Шаблон найден в следующих позициях: ";
    for (int pos : occurrences) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    return 0;
}