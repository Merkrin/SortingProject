#include <iostream>
#include "header.h"

int main() {
    srand(time(0));

    int *reference = new int[MAXIMAL_LENGTH],
            operations_amount;

    uint(*sortings[8])(int, int); // add = {sorting1, sorting 2, ...}



    return 0;
}

void first_set_reference(int reference[]) {
    for (int i = 0; i < MAXIMAL_LENGTH; ++i) {
        reference[i] = rand() % FIRST_RANDOM_MAXIMUM;
    }
}

void second_set_reference(int reference[]) {
    for (int i = 0; i < MAXIMAL_LENGTH; ++i) {
        reference[i] = rand() % SECOND_RANDOM_MAXIMUM;
    }
}

void third_set_reference(int reference[]) {
    for (int i = 0; i < FIRST_RANDOM_MAXIMUM; ++i) {
        reference[i] = MAXIMAL_LENGTH - i;
    }

    for (int i = FIRST_RANDOM_MAXIMUM;
    i < MAXIMAL_LENGTH - FIRST_RANDOM_MAXIMUM; ++i) {
        reference[i] = i;
    }

    for (int i = MAXIMAL_LENGTH - FIRST_RANDOM_MAXIMUM;
    i < MAXIMAL_LENGTH; ++i) {
        reference[i] = MAXIMAL_LENGTH - i;
    }
}

void fourth_set_reference(int reference[]) {
    for (int i = MAXIMAL_LENGTH - 1; i >= 0; --i) {
        reference[i] = i + 1;
    }
}