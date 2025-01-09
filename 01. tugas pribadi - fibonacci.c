#include <stdio.h>

int main() {
    int fib[10]; // Array untuk menyimpan 10 angka fibonacci
    //Perbaikan 1
    //Iterasi dinamis berdasarkan panjang array
    int length = sizeof(fib) / sizeof(fib[0]);  // Menghitung jumlah elemen dalam array
    
    int *ptr = fib; //pointer menunjuk ke array fib
    *ptr = 0; // elemen pertama seri fibonacci
    *(ptr + 1) = 1; // elemen kedua seri fibonacci

    //hitung elemen ke-2 sampai ke-9
    for(int i = 2; i < length; i++) 
    {
        *(ptr + i) = *(ptr + i -1) + *(ptr + i - 2); // koreksi penggunaan pointer
    }

    // mencetak 10 angka fibonacci
    for(int i = 0; i < length; i++) 
    {
        printf("%d ", *(ptr + i)); //akses value dari array ptr indeks ke i
    }

    return 0;
}
