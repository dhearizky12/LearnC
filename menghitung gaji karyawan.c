#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Fungsi untuk memvalidasi input sebagai angka
int isValidInput(const char *input) {
    int dotCount = 0; // Untuk menghitung titik desimal
    while (*input) {
        if (*input == '.') {
            dotCount++;
            if (dotCount > 1) return 0; // Lebih dari satu titik
        } else if (!isdigit(*input)) {
            return 0; // Bukan angka
        }
        input++;
    }
    return 1;
}

int main() {
    char input[100];
    float gajiKotor, pajak, gajiBersih;

    // Meminta input gaji kotor dengan validasi
    printf("Masukkan gaji kotor: ");
    while (1) {
        scanf("%s", input);

        // Validasi apakah input valid
        if (isValidInput(input)) {
            gajiKotor = atof(input); // Konversi string ke float
            break;
        } else {
            printf("Input tidak valid. Masukkan angka yang benar: ");
        }
    }

    // Hitung pajak
    pajak = 0.1 * gajiKotor;

    // Hitung gaji bersih
    gajiBersih = gajiKotor - pajak;

    // Tampilkan gaji bersih
    printf("Gaji bersih setelah dipotong pajak adalah: %.2f\n", gajiBersih);
    return 0;
}
