#include <stdio.h>

int linearSearch( int arr[], int size, int key)
{
    for ( int i = 0; i < size; i++ )
    {
        if ( arr [ i ] == key )
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr [] = {2,4,0,1,9};
    int key = 1;
    int size = sizeof(arr) / sizeof (arr[0]);

    int index = linearSearch( arr, size, key);

    if ( index != -1 )
    {
        printf("element found at index : %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}