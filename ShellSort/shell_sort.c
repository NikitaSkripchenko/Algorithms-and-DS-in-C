#include <stdio.h>
#include <stdbool.h>

const int MAX = 65536;

void print_array(int *array, int size) {
    int curr;
    for (curr = 0; curr < size; curr++) {
        printf("%d, ", array[curr]);
    }
    printf("\n");
}

bool shell_sort(int value[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = value[i];
            int j;
            for (j = i; j >= gap && value[j - gap] > temp; j -= gap) {
                value[j] = value[j - gap];
            }
            value[j] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    shell_sort(arr, n);
    print_array(arr, n);
    return 0;
}
