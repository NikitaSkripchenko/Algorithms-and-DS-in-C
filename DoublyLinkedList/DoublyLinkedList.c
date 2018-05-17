#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
    struct node *previous;
};

struct node *head = NULL;
struct node *tail = NULL;

bool is_empty() {
    return head == NULL;
}

void add_first(int key, int data) {
    struct node *cell = (struct node *) malloc(sizeof(struct node));
    cell->key = key;
    cell->data = data;
    if (is_empty()) {
        tail = cell;
    } else {
        head->previous = cell;
    }
    cell->next = head;
    head = cell;
}

void add_last(int key, int data) {

    struct node *cell = (struct node *) malloc(sizeof(struct node));
    cell->key = key;
    cell->data = data;
    if (is_empty()) {
        tail = cell;
        head = cell;
    } else {
        tail->next = cell;//cell->next = tail
        cell->previous = tail;
    }
    tail = cell;
}

struct node *delete_first() {
    //save ref to the first cell
    struct node *temp = head;
    if (is_empty()) {
        return NULL;
    }
    //one element
    if (head->next == NULL) {
        tail = NULL;
    } else {
        head->next->previous = NULL;
    }
    head = head->next;
    return temp;
}

struct node *delete_last() {
    struct node *temp = tail;

    if (is_empty()) {
        return NULL;
    }
    else if (head->next == NULL) {
        tail = NULL;
    }

    if (tail->previous == NULL) {
        head = NULL;
    } else {
        tail->previous->next = NULL;
    }
    //tail = tail->previous;
    return temp;
}

struct node *delete(int key) {
    struct node *current = head;
    struct node *previous = NULL;

    if (is_empty()) {
        return 0;
    }
    while (current->key != key) {
        if (current->next == NULL) {
            return NULL;
        } else {
            previous = current;
            current = current->next;
        }
        if (current == head) {
            head = head->next;
        } else {
            current->next->previous = current->previous;
        }
    }
    return current;
}

bool insertAfter(int key, int newKey, int data) {
    //start from the first link
    struct node *current = head;
    //if list is empty
    if (head == NULL) {
        return false;
    }
    //navigate through list
    while (current->key != key) {
        //if it is last node
        if (current->next == NULL)
            return false;
        else {
            //move to next link
            current = current->next;
        }
    }
    //create a link
    struct node *newLink = (struct node *) malloc(sizeof(struct node));
    newLink->key = newKey;
    newLink->data = data;
    if (current == tail) {
        newLink->next = NULL;
        tail = newLink;
    } else {
        newLink->next = current->next;
        current->next->previous = newLink;
    }
    newLink->previous = current;
    current->next = newLink;
    return true;
}

int list_len() {
    int len = 0;
    struct node *current;
    for (current = head; current != NULL; current = current->next) {
        len += 1;
    }
    return len;
}

void show() {
    struct node *ptr = head;
    //navigate till the end of the list
    printf("Cells in the  List: %d", list_len());
    printf("\n[ ");
    while (ptr != NULL) {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}

int main(){
    add_first(1,1);
    add_last(2,2);

    delete_last();
    delete_first();

    show();
}