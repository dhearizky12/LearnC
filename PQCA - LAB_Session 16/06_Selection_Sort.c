#include<stdio.h>

void selectionSort( int arr [], int size )
{
    for ( int i = 0; i < size - 1; i++ )
    {
        int minIndex = i;
        for ( int j = i + 1; j < size; j++ )
        {
            if ( arr[j] < arr[minIndex] )
            {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr [i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr)/ sizeof(arr[0]);

    selectionSort(arr, size);

    printf("Sorted array : \n");

    for (int i = 0; i < size; i++ )
    {
        printf ("%d ", arr[i] );
    }
    printf("\n");

    return 0;
}