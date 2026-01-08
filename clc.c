#include <stdio.h>

float kalkulator(char op, float a, float b) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/') {
        if (b != 0)
            return a / b;
        else {
            printf("Error: pembagian dengan nol!\n");
            return 0;
        }
    } else {
        printf("Operator tidak valid!\n");
        return 0;
    }
}

int main() {
    char operator;
    float angka1, angka2, hasil;

    printf("Kalkulator Sederhana\n");
    printf("Masukkan operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Masukkan angka pertama: ");
    scanf("%f", &angka1);

    printf("Masukkan angka kedua: ");
    scanf("%f", &angka2);

    hasil = kalkulator(operator, angka1, angka2);

    printf("Hasil: %.2f\n", hasil);

    return 0;
}
