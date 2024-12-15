#include <stdio.h>

int main() 
{
    int a, b;
    float result;

    // Input
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Validasi pembagian oleh nol
    if (b == 0) 
    {
        printf("Error: Division by zero is not allowed.\n");
        return 1;
    }

    // Operasi pembagian
    result = (float)a / b;

    // Output
    printf("The division of %d and %d is %.2f\n", a, b, result);
    return 0;
}
