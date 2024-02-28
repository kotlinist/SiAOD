# Лабараторная работа №1
Выполнил: студент группы БСТ2201 Жабров А.

## Оглавление
1. [Задание 1](#Задание-№1)
2. [Задание 2](#Задание-№2)
3. [Задание 3](#Задание-№3)
4. [Вывод](#Вывод)

## Задание №1
<i> Вызвать функцию print() и передать туда строку Hello, World! </i>

```c++
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

## Задание №2
Написать генератор случайных матриц (многомерных), который принимает
опциональные параметры <b>m</b>, <b>n</b>, <b>min_limit</b>, <b>max_limit</b>, где <b>m</b> и <b>n</b> указывают размер
матрицы, а <b>min_lim</b> и <b>max_lim</b> - минимальное и максимальное значение для
генерируемого числа.

```c++
vector<vector<int> > generateMatrix(int m, int n, int min, int max) {
    std::vector<std::vector<int> > matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = generateRandomNumber(min, max);
        }
    }
    return matrix;
}
```
Функция для генерации матрицы реализована в отдельном вспомогательном файле [utils.cpp](utils.cpp).


## Задание №3
Реализовать методы сортировки строк числовой матрицы в соответствии с
заданием. Оценить время работы каждого алгоритма сортировки и сравнить его со
временем стандартной функции сортировки. Испытания проводить на сгенерированных
матрицах.

Реализованы сортировки:
- [Сортировка выбором](selection.cpp)
- [Сортировка вставкой](inserts.cpp)
- [Сортировка обменом (Сортировка пузырьком)](bubble.cpp)
- [Сортировка Шелла](shell.cpp)
- [Быстрая сортировка](quick.cpp)
- [Турнирная сортировка](tournament.cpp)
- [Стандартная фкнкция сортировки для сравнения](default.cpp)


## Вывод

Сравнение производительности различных методов сортировок было выполнено с помощью утилиты hyperfine. Тесты для каждого метода выплнялись по 10 раз на случайно сгенерированных матрицах размером 1000 на 1000:

```bash
hyperfine --warmup 3 './selection 1000 1000' './inserts 1000 1000' './bubble 1000 1000' './shell 1000 1000' './quick 1000 1000' './tournament 1000 1000' './default 1000 1000'
Benchmark 1: ./selection 1000 1000
  Time (mean ± σ):      8.913 s ±  0.005 s    [User: 8.882 s, System: 0.002 s]
  Range (min … max):    8.909 s …  8.922 s    10 runs

Benchmark 2: ./inserts 1000 1000
  Time (mean ± σ):      4.754 s ±  0.016 s    [User: 4.736 s, System: 0.002 s]
  Range (min … max):    4.747 s …  4.799 s    10 runs

  Warning: Statistical outliers were detected. Consider re-running this benchmark on a quiet system without any interferences from other programs. It might help to use the '--warmup' or '--prepare' options.

Benchmark 3: ./bubble 1000 1000
  Time (mean ± σ):      7.440 s ±  0.030 s    [User: 7.414 s, System: 0.002 s]
  Range (min … max):    7.418 s …  7.506 s    10 runs

Benchmark 4: ./shell 1000 1000
  Time (mean ± σ):      4.003 s ±  0.034 s    [User: 3.982 s, System: 0.002 s]
  Range (min … max):    3.983 s …  4.078 s    10 runs

  Warning: Statistical outliers were detected. Consider re-running this benchmark on a quiet system without any interferences from other programs. It might help to use the '--warmup' or '--prepare' options.

Benchmark 5: ./quick 1000 1000
  Time (mean ± σ):      3.986 s ±  0.080 s    [User: 3.941 s, System: 0.003 s]
  Range (min … max):    3.937 s …  4.187 s    10 runs

  Warning: Statistical outliers were detected. Consider re-running this benchmark on a quiet system without any interferences from other programs. It might help to use the '--warmup' or '--prepare' options.

Benchmark 6: ./tournament 1000 1000
  Time (mean ± σ):      4.062 s ±  0.093 s    [User: 4.019 s, System: 0.004 s]
  Range (min … max):    4.013 s …  4.325 s    10 runs

  Warning: Statistical outliers were detected. Consider re-running this benchmark on a quiet system without any interferences from other programs. It might help to use the '--warmup' or '--prepare' options.

Benchmark 7: ./default 1000 1000
  Time (mean ± σ):      3.893 s ±  0.013 s    [User: 3.873 s, System: 0.004 s]
  Range (min … max):    3.870 s …  3.907 s    10 runs

Summary
  ./default 1000 1000 ran
    1.02 ± 0.02 times faster than ./quick 1000 1000
    1.03 ± 0.01 times faster than ./shell 1000 1000
    1.04 ± 0.02 times faster than ./tournament 1000 1000
    1.22 ± 0.01 times faster than ./inserts 1000 1000
    1.91 ± 0.01 times faster than ./bubble 1000 1000
    2.29 ± 0.01 times faster than ./selection 1000 1000
```

По результатам теста оказалось, что самые быстрые методы - стандартная реализация сортировки в языке с++. Самый медленный - сортировка выбором.