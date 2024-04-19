#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<int> prefix_function(const std::string& pattern) {
    int n = pattern.size();
    std::vector<int> pi(n, 0);

    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        pi[i] = j;
    }

    return pi;
}

std::vector<int> kmp_search(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrences;
    std::vector<int> pi = prefix_function(pattern);

    int n = text.size();
    int m = pattern.size();
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            occurrences.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }

    return occurrences;
}

int main(int argc, char *argv[]) {
    bool IGNORE_REGISTER = false;

    if(argc < 3 || argc > 4) {
        cout << "Использование:\nkmp -i target string\n target - искомая подстрока\n stirng - строка, в которой производится поиск\n -i - игнорировать регистр";
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

    std::vector<int> occurrences = kmp_search(str, pattern);

    if (occurrences.empty()) {
        std::cout << "Шаблон не найден в тексте." << std::endl;
    } else {
        std::cout << "Шаблон найден в следующих позициях: ";
        for (int pos : occurrences) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}