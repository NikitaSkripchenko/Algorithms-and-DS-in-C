#include <stdio.h>

void sift(int array[], int l, int r) {
    int i, j, x, k;
    i = l;
    j = 2 * l + 1;

    x = array[l]; //parent
    if ((j < r) && (array[j] < array[j + 1]))
        j++;
    while ((j <= r) && (x < array[j])) {
        k = array[i];
        array[i] = array[j];
        array[j] = k;
        i = j;
        j = 2 * j + 1;
        if ((j < r) && (array[j] < array[j + 1]))
            j++;
    }
}

int heap_sort(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    int l, r, x, i;
    l = n / 2;
    r = n - 1;
    while (l > 0) {
        l--;
        sift(arr, l, r);
    }
    while (r > 0) {
        x = arr[0];
        arr[0] = arr[r];
        arr[r] = x;
        r--;
        sift(arr, l, r);
    }
    return 1;
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
    int array[] = {5, 3, 7, 27, 9, 11, 14, 2, 8};
    int n = sizeof(array) / sizeof(array[0]);
    ft_print(array, n);
    printf("\n");
    heap_sort(array, n);
    ft_print(array, n);
    return 0;
}