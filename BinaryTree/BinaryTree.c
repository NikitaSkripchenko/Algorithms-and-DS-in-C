#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *search(struct node *node, int data) {
    if (node == NULL)
        return 0;
    if (node->data == data) {
        printf("%d", node->data);
        return node;
    }
    if (node->data < data)
        return search(node->right, data);
    if (node->data > data) {
        return search(node->left, data);
    }
    return 0;
}

struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void in_order(struct node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%d\t", node->data);
        in_order(node->right);
    } else return;
}

void pre_order(struct node *node) {
    if (node != NULL) {
        printf("%d\n", node->data);
        pre_order(node->left);
        pre_order(node->right);
    } else return;
}

void post_order(struct node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%d\n", node->data);
    }
}

struct node *insert(struct node *node, int data) {
    if (node == NULL)
        return newNode(data);
    if (data > node->data)
        node->right = insert(node->right, data);
    else if (data < node->data)
        node->left = insert(node->left, data);
    return node;
}

struct node *minVal(struct node *node) {
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *delete(struct node *node, int data) {
    if (node == NULL)
        return 0;
    if (node->data < data)
        node->right = delete(node->right, data);
    if (node->data > data)
        node->left = delete(node->left, data);
    else {
        if (node->left == NULL) {
            struct node *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct node *temp = node->left;
            free(node);
            return temp;
        }
        struct node *temp = minVal(node->right);
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    return node;
}
