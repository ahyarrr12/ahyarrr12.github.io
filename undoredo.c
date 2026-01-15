#include <stdio.h>
#include <string.h>

#define MAX 100
#define WORD_LEN 100

char undoStack[MAX][WORD_LEN];
char redoStack[MAX][WORD_LEN];
int undoTop = -1;
int redoTop = -1;

int isFull(int top) {
    return top == MAX - 1;
}

int isEmpty(int top) {
    return top == -1;
}


void push(char stack[MAX][WORD_LEN], int *top, char kata[]) {
    if (isFull(*top)) {
        printf("Stack Overflow!\n");
        return;
    }
    strcpy(stack[++(*top)], kata);

}


void pop(char stack[MAX][WORD_LEN], int *top, char kata[]) {
    if (isEmpty(*top)) {
        kata[0] = '\0';
        return;
    }
    strcpy(kata, stack[(*top)--]);
}

void typeWord(char kata[]) {
    push(undoStack, &undoTop, kata);
    redoTop = -1;
}

void undo() {
    if (isEmpty(undoTop)) {
        printf("Tidak ada yang bisa di-undo\n");
        return;
    }
    char temp[WORD_LEN];
    pop(undoStack, &undoTop, temp);
    push(redoStack, &redoTop, temp);
}

void redo() {
    if (isEmpty(redoTop)) {
        printf("Tidak ada yang bisa di-redo\n");
        return;
    }
    char temp[WORD_LEN];
    pop(redoStack, &redoTop, temp);
    push(undoStack, &undoTop, temp);
}

void display() {
    printf("Teks: \n");
    for (int i = 0; i <= undoTop; i++) {
        printf("%s", undoStack[i]);
    }
    printf("\n");
}

int main() {
    char cmd;
    char kata[WORD_LEN];

    while (1) {
        printf("\n(t) ketik kalimat (u) undo (r) redo (e) exit: ");
        scanf(" %c", &cmd);
        getchar(); 

        if (cmd == 't') {
            printf("Masukkan kalimat: ");
            scanf("%s", kata);
            typeWord(kata);

        }
        else if (cmd =='u') undo();
        else if (cmd =='r') redo();
        else if (cmd == 'e') break;

        printf("kalimat: ");
        display();
    }
    return 0;
}
