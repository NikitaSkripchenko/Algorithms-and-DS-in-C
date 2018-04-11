#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    if ((a - b) < 0)
        return a;
    else return b;
}

int jump_search(int arr[], int size, int x) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[min(size, step)] < x) {
        prev = step;
        step += step;
        if (prev > size)
            return -1;
    }
    while (arr[prev] < x) {
        prev++;
        if (arr[min(step, size)] == prev) {
            return -1;
        }
        if (arr[prev] == x)
            return prev;

    }
    return -1;
}
