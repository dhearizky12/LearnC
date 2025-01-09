#include<stdio.h>

int main()

{

int x = 2, y =3;

for (;y; printf("%d %d",x,y))

{

y = x++ <=7;

}

printf("");

return 0;

}