#include <stdio.h>
#include <string.h>

// Fungsi untuk memformat angka sesuai mata uang Indonesia
void formatRupiah(char *output, float angka) {
    int len, i, j, k;
    char buffer[50];
    sprintf(buffer, "%.0f", angka); // Mengubah angka menjadi string tanpa desimal
    len = strlen(buffer);
    j = len % 3 == 0 ? len / 3 - 1 : len / 3; // Jumlah titik yang dibutuhkan
    k = len + j; // Panjang string hasil akhir dengan titik
    output[k] = '\0';

    int posBuffer = len - 1;
    for (i = k - 1; i >= 0; i--) {
        if ((k - i) % 4 == 0 && j > 0) {
            output[i] = '.';
            j--;
        } else {
            output[i] = buffer[posBuffer--];
        }
    }
}

int main() {
    int jumlahBarang;
    float hargaPerBarang, totalBelanja, diskon, totalAkhir, batasHarga1 = 100000 , batasHarga2 = 50000 ;
    char formatTotal[50], formatDiskon[50], formatTotalAkhir[50], formatHargaPerBarang[50];

    // Meminta input jumlah barang dan harga per barang
    printf("Masukkan jumlah barang yang dibeli: ");
    scanf("%d", &jumlahBarang);

    printf("Masukkan harga per barang: ");
    scanf("%f", &hargaPerBarang);

    // Menghitung total belanja
    totalBelanja = jumlahBarang * hargaPerBarang;

    // Memberikan diskon jika total belanja melebihi batas tertentu
    if (totalBelanja > batasHarga1) 
    {
        diskon = 0.1 * totalBelanja; // Diskon 10% jika belanja > 100.000
    } else if (totalBelanja > batasHarga2) 
    {
        diskon = 0.05 * totalBelanja; // Diskon 5% jika belanja > 50.000
    }

    // Menghitung total akhir setelah diskon
    totalAkhir = totalBelanja - diskon;

    // Format angka menjadi rupiah
    formatRupiah(formatTotal, totalBelanja);
    formatRupiah(formatDiskon, diskon);
    formatRupiah(formatTotalAkhir, totalAkhir);
    formatRupiah(formatHargaPerBarang, hargaPerBarang);

    // Menampilkan hasil
    printf("\n=== Invoice Belanja Anda ===\n");
    printf("Jumlah barang yang dibeli: %d\n", jumlahBarang);
    printf("Harga per barang         : Rp%s\n", formatHargaPerBarang);
    printf("Total belanja            : Rp%s\n", formatTotal);
    printf("Diskon                   : Rp%s\n", formatDiskon);
    printf("Total yang harus dibayar : Rp%s\n", formatTotalAkhir);

    // Menampilkan pesan jika mendapatkan diskon
    if (diskon > 0) {
        printf("\nYeay! Selamat Anda mendapatkan diskon!\n");
    } else {
        printf("\nMaaf, Anda tidak mendapatkan diskon kali ini.\n");
    }

    return 0;
}
