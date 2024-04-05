# Лабараторная работа №4
# Методы поиска.

Реализовать методы поиска в соответствии с заданием. Организовать генерацию начального набора случайных данных. Для всех вариантов добавить реализацию добавления, поиска и удаления элементов. Оценить время работы каждого алгоритма поиска и сравнить его со временем работы стандартной функции поиска, используемой в выбранном языке программирования.

Задание №1:
- Бинарный поиск
- Бинарное дерево
- Фибоначчиев	Интерполяционный

Задание №2:
- Простое рехэширование
- Рехэширование с помощью псевдослучайных чисел 
- Метод цепочек

Задание № 3:

Расставить на стандартной 64-клеточной шахматной доске 8 ферзей так, чтобы ни один из них не находился под боем другого». Подразумевается, что ферзь бьёт все клетки, расположенные по вертикалям, горизонталям и обеим диагоналям
Написать программу,  которая находит хотя бы один способ решения задач.


Результат тестирования
```bash
# Генерация массива для теста
./task1-generate-input 50000 -1000000 1000000
# Запуск бэнчмарка 
export NUMBER=891518; hyperfine --warmup 5 --shell=none "./task1-binary $NUMBER" "./task1-binary-tree $NUMBER" "./task1-fibonacci $NUMBER" "./task1-interpolation $NUMBER"
Benchmark 1: ./task1-binary 891518
  Time (mean ± σ):       6.0 ms ±   0.7 ms    [User: 4.6 ms, System: 0.8 ms]
  Range (min … max):     4.9 ms …  10.3 ms    565 runs

Benchmark 2: ./task1-binary-tree 891518
  Time (mean ± σ):      4.252 s ±  0.058 s    [User: 4.211 s, System: 0.005 s]
  Range (min … max):    4.192 s …  4.357 s    10 runs

Benchmark 3: ./task1-fibonacci 891518
  Time (mean ± σ):       5.4 ms ±   0.4 ms    [User: 4.4 ms, System: 0.6 ms]
  Range (min … max):     4.8 ms …   6.6 ms    573 runs

Benchmark 4: ./task1-interpolation 891518
  Time (mean ± σ):       5.5 ms ±   0.4 ms    [User: 4.4 ms, System: 0.6 ms]
  Range (min … max):     4.8 ms …   7.4 ms    558 runs

Summary
  ./task1-fibonacci 891518 ran
    1.01 ± 0.10 times faster than ./task1-interpolation 891518
    1.10 ± 0.16 times faster than ./task1-binary 891518
  783.58 ± 53.61 times faster than ./task1-binary-tree 891518                                                                                                                                       /1m13,5s
```