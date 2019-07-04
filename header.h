#ifndef IABARCHUK_181_HEADER_H
#define IABARCHUK_181_HEADER_H

const int MINIMAL_LENGTH = 1000,
        MAXIMAL_LENGTH = 8000,
        STEP = 1000,
        FIRST_RANDOM_MAXIMUM = 9,
        SECOND_RANDOM_MAXIMUM = 10000;

//// Метод изменения местами элементов массива.
//void swap_elements(int, int, uint);
//
//// Метод, реализующий бинарный поиск для сортировки бинарными вставками.
//int binary_search(int numbers[], int, int, int, uint);

// Метод классической сортировки пузырьком.
uint classic_bubble_sort(int numbers[], int);

// Метод сортировки пузырьком с условием Айверсона - 1.
uint first_iverson_bubble_sort(int numbers[], int);

// Метод сортировки пузырьком с условием Айверсона - 1+2.
uint second_iverson_bubble_sort(int numbers[], int);

// Метод сортировки простыми вставками.
uint simple_insertion_sort(int numbers[], int);

// Метод сортировки бинарными вставками.
uint binary_insertion_sort(int numbers[], int);

// Метод заполнения эталонного массива случайными значениями от 0 до 9.
void first_set_reference(int numbers[]);

// Метод заполнения эталонного массива случайными значениями от 0 до 10000.
void second_set_reference(int numbers[]);

// Метод заполнения массива "почти" отсортированными значенииями, то есть:
// [8000, 7999, ..., 7992, 10, 11, ..., 7991, 9, 8, ..., 2, 1].
void third_set_reference(int numbers[]);

// Метод заполнения массива числами, отсортированными в обратном проядке.
void fourth_set_reference(int numbers[]);

#endif //IABARCHUK_181_HEADER_H
