#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j;
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;
    int leftArray[sizeLeft];
    int rightArray[sizeRight];

    /* Copy data to temp arrays l[] and r[] */
    for (i = 0; i < sizeLeft; i++) {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < sizeRight; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    int k = left;

    while (i < sizeLeft && j < sizeRight) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < sizeLeft) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
      are any */
    while (j < sizeRight) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left == right || right < 0) {
        return;
    } else {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int ft_print(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else {
        for (int i = 0; i < n; i++)
            printf("%d\t", arr[i]);
    }
    return 1;
}

int main() {
    int array[] = {3, 4, 1, 5, 9, 8, 5, 55, 68, 120, -56, 5, 1, 0, -88838};
    int n = sizeof(array) / sizeof(array[0]);
    ft_print(array, n);
    merge_sort(array, 0, n - 1);
    printf("\n");
    ft_print(array, n);
    return 0;
}