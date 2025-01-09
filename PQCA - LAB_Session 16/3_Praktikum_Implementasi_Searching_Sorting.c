/*
    Buatlah program yang meminta pengguna untuk memasukkan sejumlah angka,
kemudian menggunakan bubble sort untuk mengurutkan angka-angka tersebut dan
mencari angka tertentu menggunakan binary search.
*/

#include <stdio.h>

void bubbleSort( int arr[], int size )
{
    for (int i = 0; i < size -1 ; i++ )
    {
        for ( int j = 0; j < size - i - 1; j++ )
        {
            if ( arr[j] > arr [ j + 1 ] )
            {
                int temp = arr[j];
                arr[j] = arr [ j+1 ];
                arr [j+1] = temp;
            }
        }
    }
}

int binarySearch( int arr[], int size, int key )
{
    int left = 0, right = size - 1;

    while ( left <= right )
    {
        int mid = left + ( right - left ) / 2;

        if ( arr[mid] == key )
        {
            return mid;
        }

        if ( arr[mid] < key )
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main () 
{
    int n;
    printf("Enter number of elements : " );
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements : \n" );

    for ( int i = 0; i < n; i++ )
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printf("Sorted array : \n");

    for (int i = 0; i < n; i++ )
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int key;
    printf("enter the element to search : ");
    scanf("%d", &key);

    int index = binarySearch( arr, n, key );

    if ( index != -1 )
    {
        printf("element found at index : %d\n", index );
    }
    else
    {
        printf("Element  not found\n");
    }

    return 0;
}