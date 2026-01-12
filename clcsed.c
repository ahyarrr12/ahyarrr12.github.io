#include <stdio.h>

int menu() {
    int pilih;
    printf("=== KALKULATOR SEDERHANA ===\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("4. Pembagian\n");
    printf("Pilih operasi (1-4): ");
    scanf("%d", &pilih);
    return pilih;
}

int main() {
    float a, b, hasil;
    int pilihan;
    printf("Masukkan angka pertama: ");
    scanf("%f", &a);
    printf("Masukkan angka kedua: ");
    scanf("%f", &b);
  
    pilihan = menu();
    switch(pilihan) {
        case 1:
            hasil = a + b;
            printf("Hasil = %.2f\n", hasil);
            break;
        case 2:
            hasil = a - b;
            printf("Hasil = %.2f\n", hasil);
            break;
        case 3:
            hasil = a * b;
            printf("Hasil = %.2f\n", hasil);
            break;
        case 4:
                hasil = a / b;
                printf("Hasil = %.2f\n", hasil);
            break;
        default:
            printf("Pilihan tidak valid!\n");
    }
    return 0;
}
