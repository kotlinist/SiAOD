#include <iostream>
#include "stack.cpp"
#include "utils.cpp"

#include <stdio.h>
#define PRINTER(name) printer(#name, (name))
#define GET_VARIABLE_NAME(Variable) (#Variable)

using namespace std;

// Даны три стержня и n дисков различного размера. Диски можно надевать на стержни, образуя из них башни. Перенести n дисков со стержня А на стержень С, сохранив их первоначальный порядок. При переносе дисков необходимо соблюдать следующие правила:
// - на каждом шаге со стержня на стержень переносить только один диск;
// - диск нельзя помещать на диск меньшего размера;
// - для промежуточного хранения можно использовать стержень В.
// Реализовать алгоритм, используя три стека вместо стержней А, В, С. Информация о дисках хранится в исходном файле.

void printer(Stack<int> *rod1, Stack<int> *rod2) {
    printf("Move disk 1 from rod %s to rod %s\n", rod1, rod2);
}

void moveDisks(int n, Stack<int>& start, Stack<int>& end, Stack<int>& middle) {
    if (n==1) {
        end.push(start.pop());
//        cout << "Move disk 1 from rod " << GET_VARIABLE_NAME(start); //{start.name} to rod {end.name}
//        printf("name: %s\tvalue: %d\n", start, value);
        return;
    } else {
        moveDisks(n-1, start, middle, end);
//        print(f'Move disk {n} from rod {start.name} to rod {end.name}')
        end.push(start.pop());
        moveDisks(n-1, middle, end, start);
    }
}

int main(int argc, char *argv[]) {
    Stack<int> a;
    Stack<int> b;
    Stack<int> c;

    int n = stoi(read_text_from_file("lab2/task3.txt"));

    for (int i = n; i > 0 ; --i) {
        a.push(i);
    }

    cout << "Стержень A: ";
    for (auto i: a.elements) cout << i << " ";
    cout << endl;

    moveDisks(n, a,c,b);

    cout << "Стержень С: ";
    for (auto i: c.elements) cout << i << " ";

    return 0;
}