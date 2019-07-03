#include <iostream>

// Метод классической сортировки пузырьком.
uint classic_bubble_sort(int, int);

// Метод сортировки пузырьком с условием Айверсона - 1.
uint first_iverson_bubble_sort(int, int);

// Метод сортировки пузырьком с условием Айверсона - 2.
uint second_iverson_bubble_sort(int, int);

// Метод изменения местами элементов массива.
void swap_elements(int, int, uint);

// Метод заполнения эталонного массива случайными значениями от 0 до 9.
void first_set_reference(int);

// Метод заполнения эталонного массива случайными значениями от 0 до 10000.
void second_set_reference(int);

// Метод заполнения массива "почти" отсортированными значенииями, то есть:
// [8000, 7999, ..., 7992, 10, 11, ..., 7991, 9, 8, ..., 2, 1].
void third_set_reference(int);

// Метод заполнения массива числами, отсортированными в обратном проядке.
void fourth_set_reference(int);

const int minimal_length = 1000,
        maximal_length = 8000,
        step = 1000,
        first_random_maximum = 9,
        second_random_maximum = 10000;

int main() {
    srand(time(0));

    int *reference = new int[maximal_length],
            operations_amount;

    uint(*sortings[8])(int, int); // add = {sorting1, sorting 2, ...}



    return 0;
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

    bool is_swapped;

    for (int i = 0; i < array_length - 1; ++i) {
        is_swapped = false;

        // Была произведена операция присваивания.
        ++operations_amount;

        for (int j = 0; j < array_length - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap_elements(numbers[j], numbers[j + 1], operations_amount);

                // Аналогично classic_bubble_sort.
                operations_amount += 3;

                is_swapped = true;

                // Была произведена операция присваивания.
                ++operations_amount;
            }
        }

        if (!is_swapped) {
            ++operations_amount;
            break;
        }

        // Аналогично classic_bubble_sort.
        operations_amount += 3 * (array_length - i - 1) + 2;
    }

    // Аналогично classic_bubble_sort.
    operations_amount += 3 * (array_length - 1) + 2;

    return operations_amount;
}

uint second_iverson_bubble_sort(int numbers[], int array_length) {
    // Счётчик операций.
    uint operations_amount = 0;

    int t;

    do {
        t = 0;
        ++operations_amount;

        for (int i = 0; i < array_length - 1; ++i) {
            if (numbers[i] > numbers[i + 1]) {
                swap_elements(numbers[i], numbers[i + 1], operations_amount);
                t = i;
            }
            ++operations_amount;
        }
        operations_amount += 3 * (array_length - 1) + 2;

        array_length = t;

        operations_amount += 2;
    } while (array_length > 1);
}

void swap_elements(int &first_element, int &second_element, uint &operations_amount) {
    int temporary_element = first_element;
    first_element = second_element;
    second_element = temporary_element;

    // Было произведено 3 операции присваивания.
    operations_amount += 3;
}

void first_set_reference(int reference[]) {
    for (int i = 0; i < maximal_length; ++i) {
        reference[i] = rand() % first_random_maximum;
    }
}

void second_set_reference(int reference[]) {
    for (int i = 0; i < maximal_length; ++i) {
        reference[i] = rand() % second_random_maximum;
    }
}

void third_set_reference(int reference[]) {
    for (int i = 0; i < first_random_maximum; ++i) {
        reference[i] = maximal_length - i;
    }

    for (int i = first_random_maximum; i < maximal_length - first_random_maximum; ++i) {
        reference[i] = i;
    }

    for (int i = maximal_length - first_random_maximum; i < maximal_length; ++i) {
        reference[i] = maximal_length - i;
    }
}

void fourth_set_reference(int reference[]) {
    for (int i = maximal_length - 1; i >= 0; --i) {
        reference[i] = i + 1;
    }
}