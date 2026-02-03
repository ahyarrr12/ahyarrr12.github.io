#include "bst.h"

int main(){
    node *root = NULL;

    int data[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++){
        root = insert(root, data[i]);
    }

    printf("\nInorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\n\nJumlah node  : %d", countNode(root));
    printf("\nTinggi tree  : %d", height(root));

    printf("\n\nHapus node 50\n");
    root = deleteNode(root, 50);

    printf("Inorder setelah delete: ");
    inorder(root);

    clearTree(root);
    root = NULL;

    return 0;
}
