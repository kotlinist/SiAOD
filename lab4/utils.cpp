#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

int* parseInput(int argc, char *argv[]) {
    if(argc < 3) {
        cout << "Параметры m и n обязательны.";
        exit(1);
    }

    if(argc > 5) {
        cout << "Слишком много аргументов. Укажите m, n, min, max.";
        exit(1);
    }

    int args[4];
    for (int i = 1; i < argc; i++) {
        args[i-1] = stoi(argv[i]);
//        cout << args[i-1]<<"\n";
    }

    if(args[0]<1 || args[1] < 1) {
        cout << "Ожидается m > 0 и n > 0";
        exit(1);
    }

    if(argc < 5) args[3] = INT_MAX;
    if(argc == 3) args[2] = INT_MIN;

//    for(int arg : args){
//        cout << arg <<"\n";
//    }
    return args;
}

std::string read_text_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Файл не найден: " << filename << std::endl;
        std::exit(1);
    }

    std::string text;
    std::string line;
    while (std::getline(file, line)) {
        text += line + "\n";
    }

    file.close();

    return text;
}

void save_text_to_file(const std::string& filename, const std::string& text) {
    std::ofstream output(filename);
    if (output.is_open()) {
        output << text;
        output.close();
    } else {
        std::cout << "Не удалось открыть файл для записи" << std::endl;
    }
}

int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

vector<int> generateVector(int n, int min, int max) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = generateRandomNumber(min, max);
    }
    return vec;
}