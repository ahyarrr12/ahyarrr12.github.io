#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char platNomor[15];
    char jenis[10];
} Kendaraan;

typedef struct {
    Kendaraan data[MAX];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int isFull(Queue *q) {
    return q->count == MAX;
}

void enqueue(Queue *q, Kendaraan k) {
    if (isFull(q)) {
        printf("antrian penuh! kendaraan ditolak\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = k;
    q->count++;

    printf("[%s %s berhasil masuk antrian\n",
           k.jenis, k.platNomor);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("antrian kosong\n");
        return;
    }

    Kendaraan k = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;

    printf(" %s %s sedang dicuci, silakan masuk area cuci\n",
           k.jenis, k.platNomor);
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf(" antrian kosong \n");
        return;
    }

    printf("\n DAFTAR ANTRIAN \n");
    int i = q->front;
    for (int n = 1; n <= q->count; n++) {
        printf("%d. %s (%s)\n",
               n,
               q->data[i].platNomor,
               q->data[i].jenis);
        i = (i + 1) % MAX;
    }
    printf("sisa slot kosong: %d\n", MAX - q->count);
}

int main() {
    Queue q;
    Kendaraan k;
    int pilihan;
    char temp[5];

    initQueue(&q);

    do {
        printf("\n=== SISTEM ANTRIAN CLEAN & GO ===\n");
        printf("1. Daftar Antrian\n");
        printf("2. Panggil ke Pencucian\n");
        printf("3. Cek Status\n");
        printf("4. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("Masukkan Plat Nomor : ");
                fgets(k.platNomor, sizeof(k.platNomor), stdin);
                k.platNomor[strcspn(k.platNomor, "\n")] = 0;

                printf("Masukkan Jenis (Motor/Mobil) : ");
                scanf("%s", temp);

                if (strcmp(temp, "Motor") == 0)
                    strcpy(k.jenis, "Motor");
                else
                    strcpy(k.jenis, "Mobil");

                enqueue(&q, k);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                displayQueue(&q);
                break;
        }
    } while (pilihan != 4);

    return 0;
}
