#include "bst.h"

node* createNode(int value){
    node *newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL){
        printf("error: gagal mengalokasikan memori\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* insert(node *root, int value){
    if (root == NULL){
        printf("[insert] membuat node baru dengan nilai %d\n", value);
        return createNode(value);
    }

    if (value < root->data){
        printf("[insert] %d < %d ke kiri\n", value, root->data);
        root->left = insert(root->left, value);
    }
    else if (value > root->data){
        printf("[insert] %d > %d ke kanan\n", value, root->data);
        root->right = insert(root->right, value);
    }
    else {
        printf("[insert] nilai %d sudah ada\n", value);
    }

    return root;
}

node* search(node *root, int value){
    if (root == NULL){
        printf("[search] null, nilai %d tidak ditemukan\n", value);
        return NULL;
    }

    if (root->data == value){
        printf("[search] nilai %d ditemukan\n", value);
        return root;
    }

    if (value < root->data){
        printf("[search] %d < %d, cari di kiri\n", value, root->data);
        return search(root->left, value);
    }
    else {
        printf("[search] %d > %d, cari di kanan\n", value, root->data);
        return search(root->right, value);
    }
}

void inorder(node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node *root){
    if (root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node* minValueNode(node *node){
    node *current = node;
    while (current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}

node* maxValueNode(node *node){
    node *current = node;

    while (current != NULL && current->right != NULL){
        current = current->right;
    }
    return current;
}

node* deleteNode(node *root, int value){
    if (root == NULL){
        printf("[delete] nilai %d tidak ditemukan\n", value);
        return root;
    }

    if (value < root->data){
        printf("[delete] %d < %d, cari di kiri\n", value, root->data);
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data){
        printf("[delete] %d > %d, cari di kanan\n", value, root->data);
        root->right = deleteNode(root->right, value);
    }
    else {
        printf("[delete] node %d ditemukan, menghapus\n", value);

        if (root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
