/*
    Membaca dari file dapat dilakukan dengan berbagai fungsi seperti fscanf, fgets atau fread.
*/

#include <stdio.h>

int main()
{
    FILE * file;
    char buffer[100]; //Buffer area is part of the memory used as a temporary space before data moved to a file.

    //membuka file untuk membaca
    const char *filename = "../01_FileProcessing_OpenCloseFile.txt";
    file = fopen( filename, "r");

    if ( file == NULL )
    {
        printf("Error opening file!\n");
        return 1;
    }

    //membaca dari file
    while ( fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    //menutuup file
    fclose(file);

    return 0;
}

/*
    Penjelasan:
    • file = fopen("example.txt", "r"); membuka file example.txt dalam mode membaca.
    • fgets(buffer, sizeof(buffer), file); membaca satu baris dari file ke dalam buffer.
    • printf("%s", buffer); mencetak konten buffer ke layar.
    • fclose(file); menutup file.
*/