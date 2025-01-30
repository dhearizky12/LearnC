/*
    Buatlah program yang menulis serangkaian angka ke file dan kemudian membaca
    angka-angka tersebut dari file.
*/

#include <stdio.h>

int main ()
{
    FILE *file;
    int n, num;

    //mmembuka file untuk menulis
    file = fopen ("../04_FileProcessing_Latihan_Menulis_Membaca_File.txt", "w");

    if ( file == NULL )
    {
        printf("Error opening file!\n");
        return 1;
    }

    //menulis angka ke file
    printf("Enter the number of elements : ");
    scanf( "%d", &n );

    for ( int i = 0; i < n; i++ )
    {
        printf("Enter number %d : ", i +1 );
        scanf ( "%d", &num );
        fprintf(file, "%d\n", num);
    }

    //mentup file
    fclose(file);

    //membuka file untuk membaca
    file = fopen("../04_FileProcessing_Latihan_Menulis_Membaca_File.txt", "r");

    if ( file == NULL )
    {
        printf("Error opening file!\n");
        return 1;
    }

    //membaca angka dari file
    printf("Numbers in the file : \n");
    while ( fscanf(file, "%d", &num) != EOF)
    {
        printf("%d", num);
    }

    printf("\n");

    //menutup file
    fclose(file);

    return 0;
}

/*
    Penjelasan:
    • Program ini meminta pengguna untuk memasukkan sejumlah angka dan
    menyimpannya ke dalam file numbers.txt.
    • Kemudian, program membuka file numbers.txt dan membaca angka-angka
    tersebut untuk ditampilkan di layar.
*/