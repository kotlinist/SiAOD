#include <iostream>
#include "deque.cpp"
#include "utils.cpp"

using namespace std;

// Дек содержит последовательность символов для шифровки сообщений. Дан текстовый файл, содержащий зашифрованное сообщение.
// Пользуясь деком, расшифровать текст.
// Известно, что при шифровке каждый символ сообщения заменялся следующим за ним в деке по часовой стрелке через один.

void initDecryptor(Deque<char>& deq) {
    string key = "abcdefghijklmnopqrstuvwxyz";
    for (char c: key) deq.push_back(c);
}

// функция для расшифровки каждого символа
char decryptSymbol(Deque<char>& deq, char variable) {
    for(size_t i = 0; i< deq.size(); i++) {
        char symbol = deq.pop_front();
        if (symbol == variable) { // извлеченный символ == сравниваемому из текста
            deq.push_back(symbol);
            char next_symbol = deq.pop_front(); // следующий символ после symbol
            deq.push_back(next_symbol);
            // вернем последний извлченный символ для добавления в decrypted_text
            return next_symbol;
        }
        deq.push_back(symbol);
    }
    return 0;
}

// функция для расшифровки текста
string decryptText(string& text) {
    Deque<char> deq;
    initDecryptor(deq);
    string decrypted_text;
    // собирает строку из расшифрованных символов при успешной расшифровке, иначе используется исходный символ
    for (char c: text) {
        char decode_symbol = decryptSymbol(deq, tolower(c));
        if (isupper(c)) decode_symbol = toupper(decode_symbol);
        if(decode_symbol != 0) decrypted_text += decode_symbol;
        else decrypted_text += c;
    }
    return decrypted_text;
}

int main(int argc, char *argv[]) {
    string encrypted = read_text_from_file("lab2/task2.txt");
    string decrypted = decryptText(encrypted);
    cout << encrypted << endl;
    cout << decrypted << endl; // Anyone can build a fast CPU. The trick is to build a fast system.

    return 0;
}