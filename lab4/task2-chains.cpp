#include <iostream>
#include <vector>

class HashTable {
private:
    static const int TABLE_SIZE = 10;

    // Структура для представления узла списка
    struct Node {
        int key;
        int value;
        Node* next;

        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    // Вектор указателей на списки (цепочки)
    std::vector<Node*> table;

    // Хэш-функция
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE, nullptr);
    }

    // Метод добавления элемента в таблицу
    void put(int key, int value) {
        int index = hashFunction(key);
        if (table[index] == nullptr) {
            table[index] = new Node(key, value);
        } else {
            Node* newNode = new Node(key, value);
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    // Метод поиска элемента в таблице
    int find(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Возвращаем -1, если ключ не найден
    }

    // Метод вывода всех элементов таблицы
    void printAll() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                std::cout << i << ", " << "Key: " << current->key << ", Value: " << current->value << std::endl;
                current = current->next;
            }
        }
    }

    ~HashTable() {
        // Очищаем память, выделенную для узлов списка
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.put(1, 10);
    ht.put(2, 20);
    ht.put(33, 30);
    ht.put(333, 33);

    std::cout << "Value for key 3: " << ht.find(33) << std::endl;
    std::cout << "Value for key 4: " << ht.find(4) << std::endl;

    ht.printAll();

    return 0;
}
