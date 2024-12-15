#include <stdio.h>
#include <string.h>

// Fungsi utama
int main() {
    char product_name[50];
    int quantity;
    float price, total_price;

    // Input dengan format
    printf("Enter product name (max 49 characters): ");
    scanf("%49s", product_name); // Membatasi input string hingga 49 karakter untuk keamanan

    printf("Enter price per unit: ");
    scanf("%f", &price);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Hitung total harga
    total_price = price * quantity;

    // Output dengan format
    printf("\n===== INVOICE =====\n");
    printf("%-15s: %s\n", "Product", product_name); // Rata kiri untuk kolom nama
    printf("%-15s: %.2f\n", "Price per unit", price); // Float dengan 2 digit desimal
    printf("%-15s: %d\n", "Quantity", quantity); // Integer
    printf("%-15s: %.2f\n", "Total Price", total_price);
    printf("===================\n");

    return 0;
}
