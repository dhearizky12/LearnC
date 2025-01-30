#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    int *arr;

    // Alokasi memori awal
    printf("Enter the initial number of elements: ");
    scanf("%d", &n);

    arr = (int*) calloc(n, sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Mengisi array dengan nilai awal
    for (int i = 0; i < n; i++) 
    {
        arr[i] = i + 1;
    }

    // Menampilkan isi array awal
    printf("Initial array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Mengubah ukuran array
    printf("Enter the new number of elements: ");
    int new_n;
    scanf("%d", &new_n);

    arr = (int*) realloc(arr, new_n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Reallocation memory failed!\n");
        return 1;
    }

    // Menginisialisasi elemen baru jika ukuran array bertambah
    if (new_n > n) 
    {
        for (int i = n; i < new_n; i++) 
        {
            arr[i] = i + 1;
        }
    }

    // Menampilkan isi array setelah realokasi
    printf("Array after reallocation: ");
    for (int i = 0; i < new_n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Membebaskan memori
    free(arr);

    return 0;
}