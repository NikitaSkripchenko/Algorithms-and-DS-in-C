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

int main() {
    push(12);
    push(21);
    push(32);
    delete(0);
    show();

    int amount = list_len();
    printf("The list has a length of %d", amount);
}


//int del_key(int key){
//    struct node* current = head;
//    struct node* previous = NULL;
//    if(is_empty()){
//        return NULL;
//    }
//    while (current->key != key){
//        if(current->next == NULL) {
//            return NULL;
//        } else{
//            //store
//            previous = current;
//            //move
//            current = current->next;
//        }
//    }
//    if(current == head) {
//        //change first to point to next cell
//        head = head->next;
//    } else
//        previous->next = current->next;
//    return current->data;
//}
//bool add_key(int key_pos, int key, int data ){
//    struct node* current = head;
//    struct node* previous = NULL;
//    struct node *cell = (struct node*) malloc(sizeof(struct node));
//    cell->data = data;
//    if(is_empty()){
//        return false;
//    }
//    while (current->key != key_pos){
//        if(current->next == NULL) {
//            return false;
//        } else current = current->next;
//    }
//    if(current->next == NULL) {
//        current->next = cell;
//        cell->next = NULL;
//    } else {//struct node* temp = temp->next;
//        cell->next=current->next;
//        current->next=cell;
//    }
//}
//
//void add_first(int key, int data) {
//    //create new node with size of structure node
//    struct node *cell = (struct node*) malloc(sizeof(struct node));
//    //add to the new link node data from function args
//    cell->data = data;
//    //add to the new link node Next value of head
//    cell->next = head;
//    //point head to the new node link
//    head = cell;
//}
