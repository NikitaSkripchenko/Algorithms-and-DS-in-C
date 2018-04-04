#include <stdio.h>

void swap(int *one, int *two) {
    int temp = *one;
    *one = *two;
    *two = temp;
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void ft_print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


