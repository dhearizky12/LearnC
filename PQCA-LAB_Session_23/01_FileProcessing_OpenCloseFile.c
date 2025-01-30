#include <stdio.h>

int checkFileExist(const char *filename)
{
    FILE *file;
    if (file = fopen(filename, "r"))
    {
        //jika file sudah ada.
        fclose(file);
        return 0;
    }
    else
    {
        //jika file belum ada maka akan di buatkan baru
        file = fopen(filename, "w");

        if ( file == NULL )
        {
            printf("Error opening file!\n");
            return 1;
        }
        fclose(file);
        return 0;
    }
}

int main ()
{
    FILE *file;
    // membuat fungsi untuk cek apakah sudah ada file bernama 01_FileProcessing_OpenCloseFile.txt, jika tidak di temukan maka di buatkan file nya
    if ( checkFileExist("../01_FileProcessing_OpenCloseFile.txt")  == 0) 
    {
        //membuka file untuk menulis
        file = fopen("../01_FileProcessing_OpenCloseFile.txt", "a");
        if ( file == NULL)
        {
            printf ( "Error opening file!\n");
            return 1; // kenapa return 1 ? karena program tidak bisa melanjutkan eksekusi
        }

        // menulis ke file 
        fprintf(file, "Hello, World Dhea 2!\n");

        //menuutup file
        fclose(file);
    }
    return 0; // arti return 0 adalah program berjalan dengan baik
}

/*
    Penjelasan:
    • FILE *file; mendeklarasikan pointer ke tipe data FILE.
    • file = fopen("example.txt", "w"); membuka file example.txt dalam mode menulis. Jika
    file tidak dapat dibuka, fopen mengembalikan NULL.
    • file = fopen ("example.txt", "a"); membuka file example.txt dalam mode append yang artinya menulis di akhir file. Jika file tidak dapat dibuka, fopen mengembalikan NULL.
    • fprintf(file, "Hello, World!\n"); menulis string ke file.
    • fclose(file); menutup file.
*/