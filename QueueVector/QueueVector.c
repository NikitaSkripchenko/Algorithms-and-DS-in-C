#include <stdio.h>

#define MAX 4

int queue[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int show() {
    while (!is_empty()) {
        int n = remove_data();
        printf("%d ", n);
    }
}

int is_full() {
    if (itemCount == MAX) {
        printf("Full\n");
        return 1;
    } else
        return 0;
}

int is_empty() {
    if (itemCount == 0) {
        printf("Empty\n");
        return 1;
    } else
        return 0;
}

int peek() {
    if (!is_empty()) {
        return queue[front];
    } else
        printf("Queue is empty\n");
}

int insert(int data) {
    if (!is_full()) {
        if (rear == MAX - 1)
            rear = -1;
        queue[++rear] = data;
        itemCount++;
    } else
        printf("Full\n");
}

int remove_data() {
    if (!is_empty()) {
        int data = queue[front++];
        if (front == MAX)
            front = 0;
        itemCount--;
        return data;
    } else
        printf("Empty\n");
}

int main() {
}
