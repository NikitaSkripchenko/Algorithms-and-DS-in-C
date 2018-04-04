#include <stdio.h>

int head = -1;
int max = 10;
int stack[10];

int peek() {
    if (is_empty())
        printf("Stack is empty\n");
    else
        return stack[head];
}

int is_full() {
    if (head == max) return 1;
    else
        return 0;
}

int push(int data) {
    if (!is_full()) {
        head = head + 1;
        stack[head] = data;
    } else
        printf("Could not insert data, Stack is full.\n");
}

int pop() {
    int data;
    if (!is_empty()) {
        data = stack[head];
        head -= 1;
        return data;
    } else
        printf("Stack is empty\n");
}

int is_empty() {
    if (head == -1) {
        printf("empty");
        return 1;
    } else
        return 0;
}

int show() {
    while (!is_empty()) {
        int data = pop();
        printf("%d\n", data);
    }
}
