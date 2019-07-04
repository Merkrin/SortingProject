#include <iostream>
//#include "header.h"

void swap_elements(int &first_element, int &second_element,
                   uint &operations_amount) {
    int temporary_element = first_element;
    first_element = second_element;
    second_element = temporary_element;

    // Было произведено 3 операции присваивания.
    operations_amount += 3;
}

int binary_search(int numbers[], int item, int right_bound, int left_bound,
                  uint &operations_amount) {
    if (right_bound >= left_bound) {
        // Была произведена операция сравнения.
        ++operations_amount;

        if (item > numbers[right_bound]) {
            // Были произведены операции сравнения и взятия элемента массива.
            // Будет произведена операция сложения в блоке return.
            // Всего 3 операции.
            operations_amount += 3;

            return right_bound + 1;
        }

        // Были произведены операции сравнения и взятия элемента массива.
        operations_amount += 2;

        return right_bound;
    }

    // Была произведена операция сравнения.
    ++operations_amount;

    int middle = (right_bound + left_bound) / 2;

    // Были произведены операции сложения, деления и присваивания.
    // Всего 3 операции.
    operations_amount += 3;

    if (item == numbers[middle]) {
        // Были произведены операции сравнения и взятия элемента массива.
        // Будет произведена операция сложения в блоке return.
        // Всего 3 операции.
        operations_amount += 3;

        return middle + 1;
    }

    // Были произведены операции сравнения и взятия элемента массива.
    operations_amount += 2;

    if (item > numbers[middle]) {
        // Были произведены операции сравнения и взятия элемента массива.
        // Будет произведена операция сложения в блоке return.
        // Всего 3 операции.
        operations_amount += 3;

        return binary_search(numbers, item,
                             middle + 1, left_bound, operations_amount);
    }
    // Были произведены операции сравнения и взятия элемента массива.
    // Будет произведена операция сложения в блоке return.
    // Всего 3 операции.
    operations_amount += 3;

    return binary_search(numbers, item,
                         right_bound, middle - 1, operations_amount);
}

uint classic_bubble_sort(int numbers[], int array_length) {
    // Счётчик операций.
    uint operations_amount = 0;

    // В первом цикле было array_length - 1 итераций,
    // то есть было array_length - 1 сравнений, увеличений на 1
    // и операций присваивания. Тогда было 3 * (array_length-1) операций,
    // а так же была последняя проверка i < array_length - 1
    // для i = array_length - 1 и операция присваивания int i = 0.
    // Тогда всего было 3 * (array_length - 1) + 2 операций.
    // Аналогично для второго цикла было 3 * (array_length - i - 1) + 2 операций.

    for (int i = 0; i < array_length - 1; ++i) {
        for (int j = 0; j < array_length - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap_elements(numbers[j], numbers[j + 1], operations_amount);

                // 2 раза была произведена операция взятия элемента массива
                // и 1 раз - сложения. Всего 3 операции.
                operations_amount += 3;
            }

            // Было произведено сравнение элементов,
            // 2 раза - взятие элемента массива,
            // 1 раз - сложение. Всего 4 операции.
            operations_amount += 4;
        }

        operations_amount += 3 * (array_length - i - 1) + 2;
    }

    operations_amount += 3 * (array_length - 1) + 2;

    return operations_amount;
}

uint first_iverson_bubble_sort(int numbers[], int array_length) {
    // Счётчик операций.
    uint operations_amount = 0;

    bool flag;

    int i = 0;
    // Была произведена операция присваивания.
    ++operations_amount;

    do {
        flag = true;
        // Была произведена операция присваивания.
        ++operations_amount;

        for (int j = 0; j < array_length - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap_elements(numbers[j], numbers[j + 1], operations_amount);
                // 2 раза была произведена операция взятия элемента массива
                // и 1 раз - сложения. Всего 3 операции.
                operations_amount += 3;

                flag = false;
                // Была произведена операция присваивания.
                ++operations_amount;
            }

            // 1 операция сравнения, 1 операция сложения,
            // 2 операции взятия элемента массива. Всего 4 операции.
            operations_amount += 4;
        }

        ++i;
        // Аналогично classic_bubble_sort, а также
        // 2 операции в ++i и логическая операция отрицания, логическое "и" и
        // операция сравнения, то есть ещё 5 операций.
        operations_amount += 3 * (array_length - i - 1) + 2 + 5;
    } while (!flag && i < array_length);
}

uint second_iverson_bubble_sort(int numbers[], int array_length) {
    // Счётчик операций.
    uint operations_amount = 0;

    bool is_swapped;
    int inner_bound = array_length - 1,
            last_swapped_index;

    //
    ++operations_amount;

    for (int i = 0; i < array_length - 1; ++i) {
        is_swapped = false;

        // Была произведена операция присваивания.
        ++operations_amount;

        for (int j = 0; j < inner_bound; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap_elements(numbers[j], numbers[j + 1], operations_amount);

                // Аналогично classic_bubble_sort.
                operations_amount += 3;

                is_swapped = true;

                // Была произведена операция присваивания.
                ++operations_amount;

                last_swapped_index = j;
            }

            // 1 операция сравнения, 1 операция сложения,
            // 2 операции взятия элемента массива. Всего 4 операции.
            operations_amount += 4;
        }

        // Аналогично classic_bubble_sort.
        operations_amount += 3 * (array_length - i - 1) + 2;

        if (!is_swapped) {
            // Логическое отрицание.
            ++operations_amount;
            break;
        }

        // Логическое отрицание.
        ++operations_amount;

        inner_bound = last_swapped_index;
    }

    // Аналогично classic_bubble_sort.
    operations_amount += 3 * (array_length - 1) + 2;

    return operations_amount;
}

uint simple_insertion_sort(int numbers[], int array_length) {
    uint operations_amount = 0;
    int key,
            j;

    for (int i = 1; i < array_length; ++i) {
        key = numbers[i];
        j = i - 1;

        // Были произведены 2 операции присваивания,
        // 1 - взятия элемента массива, 1 - вычитания.
        // Всего 4 операции.
        operations_amount += 4;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            --j;

            // Были произведены 2 операции сравнения,
            // 3 - взятия элемента массива, 1 - логического И,
            // 2 - арифметические, 2 - присваивания.
            // Всего 10 операций.
            operations_amount += 10;
        }
        // Для выхода из цикла условие проверилось ещё раз.
        // То есть были произведены 2 операции сравнения,
        // 1 - логическое И и 1 - взятие элемента массива.
        // Всего 4 операции.
        operations_amount += 4;

        numbers[j + 1] = key;

        // Были произведены опреация сложения,
        // взятия элемента массива и присваивания.
        // Всего 3 операции.
        operations_amount += 3;
    }

    operations_amount += 3 * (array_length - 1) + 2;

    return operations_amount;
}

uint binary_insertion_sort(int numbers[], int array_length) {
    uint operations_amount = 0;
    int element_location,
            j,
            selected_element;

    for (int i = 1; i < array_length; ++i) {
        j = i - 1;

        // Были произведены операции присваивания и вычитания.
        operations_amount += 2;

        selected_element = numbers[i];

        // Были произведены операции присваивания и взятия элемента массива.
        operations_amount += 2;

        element_location = binary_search(numbers, selected_element, 0, j, operations_amount);

        // Была произведена операция присваивания.
        ++operations_amount;

        while (j >= element_location) {
            numbers[j + 1] = numbers[j];
            --j;
        }
        numbers[j + 1] = selected_element;
    }

    operations_amount += 3 * (array_length - 1) + 2;
}

