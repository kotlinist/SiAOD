#include <iostream>
#include <sstream>
#include "utils.cpp"

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для вставки нового узла в дерево
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Функция для поиска узла с заданным значением
TreeNode* search(TreeNode* root, int value) {
    if (root == nullptr || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Вспомогательная функция для нахождения узла с минимальным значением в дереве
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Функция для удаления узла из дерева
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // Узел с одним потомком или без потомков
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Узел с двумя потомками: получаем преемника (самый маленький в правом поддереве)
        TreeNode* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Функция для обхода дерева и вывода его содержимого
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

int main(int argc, char *argv[]) {
    TreeNode* root = nullptr;
    root = insert(root, 123);

    int target;
    if(argc==2) {
        string input = read_text_from_file("vec.txt");
        stringstream ss(input);
        string num;
        while (ss >> num) {
            insert(root, stoi(num));
        }
        target = stoi(argv[1]);
    } else if(argc==4) {
        int n = stoi(argv[1]);
        int min = stoi(argv[2]);
        int max = stoi(argv[3]);

        root = insert(root, 123);
        for (size_t i=0; i<n; i++) {
            root = insert(root, generateRandomNumber(min, max));
        }

        inorderTraversal(root);
        std::cout << std::endl;

        cout << "Число для удаления: ";
        int del;
        cin >> del;
        root = deleteNode(root, del);

        inorderTraversal(root);
        std::cout << std::endl;

        cout << "Число для поиска: ";
        cin >> target;
    } else{
        exit(1);
    }

    TreeNode* searchResult = search(root, target);
    if (searchResult != nullptr) {
        std::cout << "Элемент с значением " << target << " найден." << std::endl;
    } else {
        std::cout << "Элемент с значением " << target << " не найден." << std::endl;
    }

    return 0;
}
