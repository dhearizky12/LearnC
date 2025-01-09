
#include <stdio.h>

#include <stdlib.h>

 

void main() {                

 

int c, n, x=5;

    scanf("%d", &n);

        for (c=1; c<=n; c++)

            switch(x) {

            case 1: x=(x+3)%4; break;

            case 2: x*=4; break;

            case 3: x--; break;

            default: x=(x*4)%4+1;

            }

printf("%d\n", x);

}

 