#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *arr;
    int n;

    srand(time(0)); //inisialisasi random number generator ( seed untuk pengacakan)

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    //Alokasi memori
    arr = (int*) malloc (n * sizeof(int));
    if ( arr == NULL )
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //mengisi array dengan nilai acak / random
    for ( int i = 0; i < n; i++ )
    {
        arr[i] = rand() % 100 ; //Nilai acak antara 0 dan 99
    }

    //Menampilkan isi array
    printf("Array elements : \n");
    for ( int i = 0; i < n; i++ )
    {
        printf("%d ,", arr[i]);
    }

    printf("\n");

    //membebaskan memori 
    free (arr);

    return 0;
}