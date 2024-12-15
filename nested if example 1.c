#include <stdio.h>

int main() {
    // Input data
    int usia = 30;
    char pekerjaan[] = "pegawai tetap";
    int penghasilan = 10000000; // dalam Rupiah
    int jumlah_hutang = 2000000;

    // Logika penentuan kelayakan
    if (usia >= 21) { // Syarat usia minimal
        if (strcmp(pekerjaan, "pegawai tetap") == 0 || strcmp(pekerjaan, "wirausaha") == 0) { // Syarat pekerjaan
            if (penghasilan > 5000000) { // Syarat penghasilan minimal
                if (jumlah_hutang < penghasilan * 0.3) { // Syarat rasio hutang
                    printf("Pinjaman disetujui.\n");
                } else {
                    printf("Pinjaman ditolak karena rasio hutang terlalu tinggi.\n");
                }
            } else {
                printf("Pinjaman ditolak karena penghasilan terlalu rendah.\n");
            }
        } else {
            printf("Pinjaman ditolak karena jenis pekerjaan tidak memenuhi syarat.\n");
        }
    } else {
        printf("Pinjaman ditolak karena usia di bawah 21 tahun.\n");
    }

    return 0;
}
