#include <stdio.h>
#include <stdbool.h>

void quick_sort(int array[], int l, int r) {
    int i, j, k, x;
    i = l;
    j = r;
    x = array[(l + r) / 2];
    do {
        while (array[i] < x)
            i++;
        while (array[j] > x)
            j--;
        if (i <= j) {
            k = array[i];
            array[i] = array[j];
            array[j] = k;
            i++;
            j--;
        }
    } while (i < j);
    if (l < j)
        quick_sort(array, l, j);
    if (i < r)
        quick_sort(array, i, r);
}

int ft_print(int array[], int n) {
    if (n == 0) {
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d\t", array[i]);
        }
    }
    return 1;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 8, 8, 7, 6, 5, 4, 3, 2, 1, 0,};
    int n = sizeof(array) / sizeof(array[0]);
    ft_print(array, n);
    printf("\n");
    quick_sort(array, 0, n - 1);
    ft_print(array, n);
    return 0;
}
