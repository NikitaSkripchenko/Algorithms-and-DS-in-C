#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *previous;
};

struct node *last = NULL;

int is_empty() {
    if (last == NULL)
        return 1;
    else return 0;
}

void push(int value) {
    struct node *cell = (struct node *) malloc(sizeof(struct node));
    cell->value = value;
    cell->previous = last;
    last = cell;
}

int pop() {
    if (is_empty()) {
        return 0;
    }
    struct node *temporary = last;
    int temp = temporary->value;
    last = last->previous;
    free(temporary);
    return temp;
}

void show() {
    struct node *cur_point = last;
    printf("\n Contents of the list:\n");
    while (cur_point != NULL) {
        printf(" elem is %d \n", cur_point->value);
        cur_point = cur_point->previous;
    }
    free(cur_point);
}


int length() {
    int length = 0;
    struct node *current = last;
    while (current != NULL) {
        length++;
        current = current->previous;
    }
    free(current);
    return length;
}

