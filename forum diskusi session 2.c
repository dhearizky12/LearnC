#include <stdio.h>
#include <stdbool.h>

// Prototipe fungsi
void SearchEvenOddNumbers(int start, int end, bool isEven);

int main()
{
    int start, end;

    printf( "Masukkan awal rentang : " );
    scanf( "%d", &start );
    printf ("Masukkan akhir rentang : ");
    scanf( "%d", &end );

    while ( start > end )
    {
        printf( "Awal rentang harus lebih kecil dari akhir rentang.\nPlease input valid number\n");
        printf( "Masukkan awal rentang : " );
        scanf( "%d", &start );
        printf ("Masukkan akhir rentang : ");
        scanf( "%d", &end );
    }

    printf("Angka genap dalam rentang %d - %d : \n", start, end );
    SearchEvenOddNumbers( start, end, true);

    printf("Angka ganjil dalam rentang %d - %d : \n", start, end );
    SearchEvenOddNumbers( start, end, false);
    
    return 0;
}

void SearchEvenOddNumbers(int start, int end, bool isEven)
{
    for ( int i = start; i <= end; i++ )
    {
        if ( ( i % 2 == 0 ) == isEven )
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}