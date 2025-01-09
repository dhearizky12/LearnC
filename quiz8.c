#include <stdio.h>

int main() {

    int n; 

    printf("Masukkan nilai n: "); 

    scanf("%d", &n); 

    if (n > 0)

        n++;

    if (n < 5)

        n -= 1;

    else

        n--;

    printf("%d\n", n); 

    return 0;

}