#include <stdio.h>
#include <string.h>

#define MAX_BARANG 100

// Struktur untuk menyimpan data barang
typedef struct {
    char nama[50];
    float harga;
    int jumlah;
} Barang;

int main() {
    Barang database[MAX_BARANG];
    int totalBarang = 0;
    char tambahBarang;
    int pilihan, jumlahBeli;
    float totalBelanja = 0.0, diskon = 0.0, totalAkhir;

    printf("=== Program Database Barang dengan Diskon ===\n");

    // Input data barang ke dalam database
    do {
        if (totalBarang >= MAX_BARANG) {
            printf("Database penuh. Tidak dapat menambah barang lagi.\n");
            break;
        }

        printf("\nMasukkan nama barang: ");
        scanf(" %[^\n]", database[totalBarang].nama);

        printf("Masukkan harga barang: ");
        scanf("%f", &database[totalBarang].harga);

        printf("Masukkan jumlah stok barang: ");
        scanf("%d", &database[totalBarang].jumlah);

        totalBarang++;

        printf("\nApakah Anda ingin menambah barang lagi? (y/n): ");
        scanf(" %c", &tambahBarang);

    } while (tambahBarang == 'y' || tambahBarang == 'Y');

    // Menampilkan database barang
    printf("\n=== Database Barang ===\n");
    printf("%-3s %-20s %-10s %-10s\n", "No", "Nama Barang", "Harga", "Stok");
    printf("----------------------------------------------\n");
    for (int i = 0; i < totalBarang; i++) {
        printf("%-3d %-20s Rp%-9.2f %-10d\n", i + 1, database[i].nama, database[i].harga, database[i].jumlah);
    }

    // Memilih barang untuk pembelian
    do {
        printf("\nMasukkan nomor barang yang ingin dibeli (0 untuk selesai): ");
        scanf("%d", &pilihan);

        if (pilihan == 0) {
            break;
        }

        if (pilihan < 1 || pilihan > totalBarang) {
            printf("Nomor barang tidak valid. Coba lagi.\n");
            continue;
        }

        Barang *barangDipilih = &database[pilihan - 1];

        printf("Masukkan jumlah yang ingin dibeli dari %s: ", barangDipilih->nama);
        scanf("%d", &jumlahBeli);

        if (jumlahBeli > barangDipilih->jumlah) {
            printf("Stok tidak mencukupi. Tersedia %d.\n", barangDipilih->jumlah);
        } else {
            barangDipilih->jumlah -= jumlahBeli;
            totalBelanja += barangDipilih->harga * jumlahBeli;
        }

    } while (pilihan != 0);

    // Memberikan diskon berdasarkan total belanja
    if (totalBelanja > 100000) {
        diskon = 0.1 * totalBelanja; // Diskon 10% jika belanja > 100.000
    } else if (totalBelanja > 50000) {
        diskon = 0.05 * totalBelanja; // Diskon 5% jika belanja > 50.000
    }

    totalAkhir = totalBelanja - diskon;

    // Menampilkan total belanja dan diskon
    printf("\n=== Ringkasan Belanja ===\n");
    printf("Total belanja: Rp%.2f\n", totalBelanja);
    printf("Diskon: Rp%.2f\n", diskon);
    printf("Total yang harus dibayar: Rp%.2f\n", totalAkhir);

    return 0;
}
