#include <stdio.h>

#define MAX 10 //size of array

void swap(int *one, int *two) {
    int temp = *one;
    *one = *two;
    *two = temp;
}


void ft_print(int array[]) {
    for (int i = 0; i < MAX; i++) {
        printf(" %d ", array[i]);
    }
    printf("\n");
}


void shake_sort(int array[]) {
    int p, i;
    for (p = 1; p <= MAX / 2; p++) {
        for (i = p - 1; i < MAX - p; i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
            }
        }
        for (i = MAX - p - 1; i >= p; i--) {
            if (array[i] < array[i - 1]) {
                swap(&array[i], &array[i - 1]);
            }
        }
    }
}


//int main() {
//    int array[MAX] = {1, 17, 2, 90, 15, -2, 0, 9, 21, 12};
//    ft_print(array);
//    shake_sort(array);
//
//    ft_print(array);
//
//
//    return 0;
//}