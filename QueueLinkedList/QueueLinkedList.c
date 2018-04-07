#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *last = NULL;
struct node *head = NULL;

bool is_empty() {
    if (head == NULL)
        return true;
    else
        return false;
}

void push(int value) {
    struct node *cell = (struct node *) malloc(sizeof(struct node));
    cell->value = value;
    cell->next = NULL;
    if (is_empty()) {
        head = cell;
        last = cell;
    } else {
        struct node *temp = last;
        last = cell;
        temp->next = cell;
    }
}

int pop() {
    if (is_empty()) {
        return 0;
    } else {
        struct node *temp = head;
        int tempOne = temp->value;
        head = head->next;
        free(temp);
        return tempOne;

    }
}

void show() {
    struct node *cur_point = head;
    printf("\n Contents of the list:\n");
    while (cur_point != NULL) {
        printf("  Elem is %d \n", cur_point->value);
        cur_point = cur_point->next;
    }
    free(cur_point);
}
