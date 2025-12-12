#include <stdio.h>

int hitung_a_rekursif(const char *teks, int indeks) {
    if (teks[indeks] == '\0')
        return 0;

    int jumlah = (teks[indeks] == 'a' || teks[indeks] == 'A') ? 1 : 0;

    return jumlah + hitungA_rekursif(teks, indeks + 1);
}

int main() {
    char kalimat[100];

    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    printf("Jumlah huruf 'a' = %d\n", hitung_a_rekursif(kalimat, 0));
    return 0;
}

//TC = O(n)
//SC = O(n)
