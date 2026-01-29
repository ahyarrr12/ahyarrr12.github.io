#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* createNode(int value);
node* insert(node *root, int value);
node* search(node *root, int value);

void inorder(node *root);
void preorder(node *root);
void postorder(node *root);

node* deleteNode(node *root, int value);

node* minValueNode(node *node);
node* maxValueNode(node *node);

int height(node *root);
int countNode(node *root);
int countLeave(node *root);
int printTree(node *root, int level);
int freeTree(node *root);

#endif