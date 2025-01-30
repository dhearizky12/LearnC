#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    //Alokasi memory dengan menggunakan calloc 
    arr = (int*) calloc(n, sizeof(int));

    if ( arr == NULL )
    {
        printf( "Memory allocation failed!\n");
        return 1;
    }

    //mengisi array 
    for ( int i = 0; i < n; i++ )
    {
        arr[i] = i + 1;
    }

    //menapilkan isi array
    for ( int i = 0; i < n; i++ )
    {
        printf("%d", arr[i]);
    }

    // free ( arr);

    printf("\n");

    //mengubah ukuran array 
    printf("Enter the new number of elements : ");
    scanf("%d", &n);

    arr = (int*) realloc ( arr, n * sizeof(int));

    if ( arr == NULL )
    {
        printf ( "Reallocation memory failed!\n");
        return 1;
    }

    //menampilkan isi array setelah realokasi
    for ( int i = 0; i < n; i++ )
    {
        printf("%d", arr[i]);
    }

    printf("\n");

    //membebaskan memory
    free ( arr ); // kenapa kita harus selalu membebaskan memory ? karena jika tidak, maka memory akan terus terpakai dan tidak bisa digunakan oleh program lain.

    return 0;
}

/*
    Penjelasan:
    • arr = (int*)calloc(n, sizeof(int)); mengalokasikan memori untuk n elemen integer
    dan menginisialisasi semua elemen dengan nol.
    • arr = (int*)realloc(arr, n * sizeof(int)); mengubah ukuran blok memori yang telah
    dialokasikan.
    • free(arr); membebaskan memori yang telah dialokasikan.
*/
