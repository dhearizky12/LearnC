	

#include <stdio.h>

 

int main()

{

int a[9] = {27, 23, 17, 51, 21, 23, 29, 41, 43};

int i, j, m;

i = ++a[4];

j= a[1]++;

m = a[i++];

printf("%d, %d, %d", i, j, m);

return 0;

}