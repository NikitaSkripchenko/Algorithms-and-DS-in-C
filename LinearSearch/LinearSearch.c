#include <stdio.h>

#define MAX 5

int linearSearch(int array[], int x) {
    for (int index = 0; index < MAX; index++)
        if (array[index] == x) {
            return index;
        }
    return -1;
}