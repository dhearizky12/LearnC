#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int hasil = 0;

    for ( i =0; i < 60; i++)
    {
        if ( i %5 ==1 && i%6 == 0)
        {
            printf("%d\n",i);
            hasil = hasil +i;
        }
    }
printf("\n hasil penjumlahan bil tsb adalah %d\n", hasil);
}