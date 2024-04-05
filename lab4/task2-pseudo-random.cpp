#include <iostream>
#define SIZE 10

class HashTable {
private:
    int* table;

public:
    HashTable() {
        srand(time(0));
        table = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;   // Используем -1 для обозначения пустой ячейки
        }
    }

    int hashFunction(int key) {
        return key % SIZE;   // Простейшая хеш-функция - остаток от деления на размер таблицы
    }

    void put(int key, int value) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = rand() % SIZE;
        }

        table[index] = value;
    }

    void printAll() {
        for (int i = 0; i < SIZE; i++) {
            std::cout << "Ячейка " << i << ": ";
            if (table[i] != -1) {
                std::cout << table[i];
            } else {
                std::cout << "Пусто";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.put(1, 10);
    hashTable.put(2, 20);
    hashTable.put(3, 30);
    hashTable.put(4, 40);
    hashTable.put(88, 599);
    hashTable.put(888, 5999);

    hashTable.printAll();

    return 0;
}
