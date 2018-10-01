#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *data;
    int last;
    unsigned capacity;
};

struct Array *createArray(unsigned capacity) {
    struct Array *array = (struct Array *) malloc(sizeof(struct Array));
    array->capacity = capacity;
    array->last = -1;
    array->data = (int *) malloc(array->capacity * sizeof(int));
    return array;
}

int is_full(struct Array *array) { return ((array->last + 1) == array->capacity); }

int is_empty(struct Array *array) { return (array->last < 0); }

void Push(struct Array *array, int item) {
    if (is_full(array))
        return;
    array->last = array->last + 1;
    array->data[array->last] = item;

    printf("%d added to list\n", item);
}

int Delete(struct Array *array, int index) {
    if (index <= array->last && index >= 0) {
        if (!is_empty(array)) {
            int temp = array->data[index];
            for (int i = index; i <= array->last; i++) {
                array->data[i] = array->data[i + 1];
            }
            array->data[array->last] = 0;
            array->last = array->last - 1;
            printf("%d deleted from list ", temp);
            return temp;
        }
    } else {
        return 0;
    }
    return 1;
}

void Print(struct Array *array) {
    for (int i = 0; i <= array->last; i++) {
        printf("%d\t", array->data[i]);
    }
}
