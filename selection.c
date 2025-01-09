#include <stdio.h>


int main ()
{
    int a,b;
    float result;

    printf("Enter two integers : ");
    scanf("%d %d", &a, &b);

    if ( b == 0 )
    {
        printf("error: Division by zero is not allowed.\n");
        return 1;
    }


}

