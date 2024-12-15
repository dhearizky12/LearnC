#include <stdio.h>
#include <stdbool.h>
#define phi 3.14

// Deklarasi fungsi
void LuasKelilingPersegi();
void LuasKelilingPersegiPanjang();
void LuasKelilingLingkaran();
bool validateInput(float *value);

int main() {
    int choice;
    do {
        printf("===============================================================");
        printf("\n| Selamat datang pada program perhitungan Luas dan Keliling |");
        printf("\n==============================================================");
        printf("\n| Pilih jenis bangun datar yang akan dihitung : |");
        printf("\n| 1. Persegi |");
        printf("\n| 2. Persegi Panjang |");
        printf("\n| 3. Lingkaran |");
        printf("\n| 4. Exit |");

        printf("\n\nPilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                LuasKelilingPersegi();
                break;
            case 2:
                LuasKelilingPersegiPanjang();
                break;
            case 3:
                LuasKelilingLingkaran();
                break;
            case 4:
                printf("\nTerima kasih telah menggunakan program ini. Semoga harimu menyenangkan!\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 4);

    return 0;
}

// Fungsi untuk validasi input numerik
bool validateInput(float *value) 
{
    if (scanf("%f", value) == 1) 
    {
        return true; // Input valid
    } 
    else 
    {
        printf("\nInput tidak valid. Masukkan angka!\n");
        while (getchar() != '\n'); // Bersihkan buffer input
        return false; // Input tidak valid
    }
}

void LuasKelilingPersegi() {
    float sisi, luas, keliling;

    printf("\n| Luas dan Keliling Persegi |\n");
    do {
        printf("Input sisi (cm): ");
    } while (!validateInput(&sisi)); // Validasi input

    luas = sisi * sisi;
    keliling = sisi * 4;

    printf("\nLuas Persegi: %.2f cm^2\n", luas);
    printf("Keliling Persegi: %.2f cm\n\n", keliling);
}

void LuasKelilingPersegiPanjang() {
    float p, l, luas, keliling;

    printf("\n| Luas dan Keliling Persegi Panjang |\n");
    do {
        printf("Input Panjang (cm): ");
    } while (!validateInput(&p)); // Validasi input

    do {
        printf("Input Lebar (cm): ");
    } while (!validateInput(&l)); // Validasi input

    luas = p * l;
    keliling = 2 * (p + l);

    printf("\nLuas Persegi Panjang: %.2f cm^2\n", luas);
    printf("Keliling Persegi Panjang: %.2f cm\n\n", keliling);
}

void LuasKelilingLingkaran() {
    float r, luas, keliling;

    printf("\n| Luas dan Keliling Lingkaran |\n");
    do {
        printf("Input jari-jari (cm): ");
    } while (!validateInput(&r)); // Validasi input

    luas = phi * r * r;
    keliling = 2 * phi * r;

    printf("\nLuas Lingkaran: %.2f cm^2\n", luas);
    printf("Keliling Lingkaran: %.2f cm\n\n", keliling);
}
