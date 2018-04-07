#include <stdio.h>
#include <stdbool.h>

#define MAX 10

bool swap(int *one, int *two) {
    int temp = *one;
    *one = *two;
    *two = temp;
    return true;
}

void gnome_sort(int array[]) {
    int i = 1;
    int j = 2;
    while (i < MAX) {
        if (array[i - 1] >= array[i]) {
            i = j;
            j++;
        } else {
            swap(&array[i - 1], &array[i]);
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
    }
}

void ft_print(int array[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//int main() {
//    int array[MAX] = {10, -2, 4, 100, 20, 12, 21, 8, 9, 11};
//    ft_print(array);
//    gnome_sort(array);
//    ft_print(array);
//    return 0;
//}