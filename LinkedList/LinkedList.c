#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

int is_empty() {
    if (head == NULL)
        return 1;
    else return 0;
}

void show() {
    struct node *ptr = head;
    if (!is_empty()) {
        printf("\n[ ");
        while (ptr != NULL) {
            printf(" (%d), ", ptr->data);
            ptr = ptr->next;
        }
        printf(" ] \n");
        free(ptr);
    } else {
        return;
    }
}

void push(int value) {
    struct node *cell = (struct node *) malloc(sizeof(struct node));
    cell->data = value;
    cell->next = NULL;
    if (is_empty()) {
        head = cell;
        last = cell;
    } else {
        // struct node* temp = last;
        last->next = cell;
        last = cell;
    }
}

int delete(int pos) {
    struct node *temp = head;
    struct node *previous = NULL;
    if (is_empty()) {
        return 0;
    }
    for (int i = 0; i < pos; i++) {
        if (temp->next == NULL) {
            return 0;
        } else {
            //store
            previous = temp;
            //move
            temp = temp->next;
        }
    }
    if (temp == head) {
        //change first to point to next cell
        head = head->next;
    } else
        previous->next = temp->next;
    return temp->data;
}

int list_len() {
    int len = 0;
    struct node *current;
    for (current = head; current != NULL; current = current->next) {
        len += 1;
    }
    free(current);
    return len;
}

