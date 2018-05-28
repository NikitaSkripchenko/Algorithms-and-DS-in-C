#include <stdio.h>

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void ft_print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void countSort(int arr[], int n, int exp) {
    int count[10] = {}, fin[n];
    int i;
    for (i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        fin[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = fin[i];
}


void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}


int main() {
    int arr[] = {23, 15, 43,};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    ft_print(arr, n);
    return 0;

}