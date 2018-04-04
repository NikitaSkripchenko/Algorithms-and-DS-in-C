#include <stdio.h>

#define MAX 7 //your size of array

int intersectionSort(int array[]) {
    int pos, value;
    for (int i = 0; i < MAX; i++) {
        value = array[i];
        pos = i;
        while (pos > 0 && array[pos - 1] > value) {
            array[pos] = array[pos - 1];
            pos = pos - 1;
        }
        if (pos != i) {
            array[pos] = value;
        }
    }
    return *array;
}

//print function
void print(int array[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }
}
