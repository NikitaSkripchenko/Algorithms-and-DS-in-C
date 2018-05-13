#include <stdio.h>

const int MAX = 65536;

void print_array(int *array, int size) {
    int curr;
    for (curr = 0; curr < size; curr++) {
        printf("%d, ", array[curr]);
    }
    printf("\n");
}

void count_sort(int value[], int n) {
    int count[MAX];
    for (int i = 0; i < MAX - 1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
        count[value[i]] = count[value[i]] + 1;

    int index = 0;
    for (int i = 0; i < MAX - 1; i++)
        for (int j = 0; j < count[i]; j++) {
            value[index++] = i;
        }
    print_array(count, n);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 5;
    count_sort(arr, n);
    print_array(arr, n);
    return 0;
}
