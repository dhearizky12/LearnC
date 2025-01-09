#include <stdio.h>
#include <ctype.h>> //used by isdigit function
#include <stdlib.h> // used by atoi function

int isValidInput( const char *input )
{
    //memeriksa apakah stgring kosong (apakah user tidak menginput value apapun )
    if ( *input == '\0')
    {
        return 0;
    }

    //memeriksa apakah setiap karakter dalam string  berupa digit angka
    while ( *input )
    {
        if ( !isdigit(*input))
        {
            return 0;
        }
        input ++;
    }

    //jika lolos validasi, return value 1;
    return 1;
}

int main()
{
    int num1, num2, num3;

    InputRule( &num1 );
    InputRule( &num2 );
    InputRule( &num3 );

    int sum = num1 + num2 + num3;
    int diff = num1 - num2 - num3;
    int product = num1 * num2 * num3;
    double division = num1 / num2 / num3 ;
    double avg = (sum/3.0);

    //menampilkan hasil operasi
    printf("==================================");
    printf("\nHasil operasi : \n");
    printf("Penjumlahan : %d\n", sum);
    printf("Pengurangan : %d\n", diff);
    printf("Perkalian : %d\n", product);
    printf("Pembagian : %.2f\n", avg);
    printf("Rata - rata : %.2f\n", avg);
    printf("==================================");

    return 0;
}

void InputRule( int *input )
{
    char buffer[100];
    while (1)
    {
        printf("Masukkan bilangan bulat : ");
        scanf("%s", buffer );

        if ( isValidInput( buffer ) )
        {
            *input = atoi(buffer); // konversi string ke integer(Converts the string pointed to, by the argument str to an integer (type int).)
            if (*input > 0)
            {
                break; // input valid, keluar dari loop
            }
            else 
            {
                printf("\nInput tidak boleh negatif atau kurang dari 0\n" );
            }
        }
        else 
        {
            printf("\nInput tidak valid. Please input valid number. [Harus bilangan bulat]\n");
        }
    }
}