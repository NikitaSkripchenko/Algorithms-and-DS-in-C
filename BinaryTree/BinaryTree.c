#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *search(struct node *node, int data) {
    // Base Cases
    if (node == NULL)
        return 0;
    if (node->data == data) {
        printf("%d", node->data);
        return node;
    }
    //Data is greater than input
    if (node->data < data)
        return search(node->right, data);
    //Data is smaller than root's key
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

//Inorder tree traversal
void in_order(struct node *node) {
    if (node != NULL) {
        in_order(node->left);
        printf("%d\t", node->data);
        in_order(node->right);
    } else return;
}

//Preorder tree traversal
void pre_order(struct node *node) {
    if (node != NULL) {
        printf("%d\t", node->data);
        pre_order(node->left);
        pre_order(node->right);
    } else return;
}

//Postorder tree traversal
void post_order(struct node *node) {
    if (node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%d\t", node->data);
    }
}

struct node *insert(struct node *node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data > node->data) {
        node->right = insert(node->right, data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    }
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
        return NULL;
    if (node->data < data)
        node->right = delete(node->right, data);
    else if (node->data > data)
        node->left = delete(node->left, data);
    else if (node->data == data) {
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


int main() {
    struct node *root = NULL;
    root = insert(root, 150);
    insert(root, 200);
    insert(root, 170);
    insert(root, 180);
    insert(root, 160);
    insert(root, 50);
    insert(root, 100);
    insert(root, 110);
    insert(root, 90);
    insert(root, 10);
    insert(root, 20);
    delete(root, 150);
    //pre_order(root);
    delete(root, 10);

    //in_order(root);

    delete(root, 170);
    pre_order(root);
    //post_order(root);


    return 0;
}