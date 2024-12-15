#include <stdio.h>
#include <string.h>

// Produk
char product1_name[] = "Laptop";
float product1_price = 5000.00;
int product1_stock = 5;

char product2_name[] = "Smartphone";
float product2_price = 1500.00;
int product2_stock = 10;

// Keranjang
int cart_quantity1 = 0, cart_quantity2 = 0;

// Fungsi menambahkan produk ke keranjang
void add_to_cart(int product_id, int quantity) {
    if (product_id == 1 && product1_stock >= quantity) {
        cart_quantity1 += quantity;
        product1_stock -= quantity;
        printf("Added %d Laptop(s) to cart.\n", quantity);
    } else if (product_id == 2 && product2_stock >= quantity) {
        cart_quantity2 += quantity;
        product2_stock -= quantity;
        printf("Added %d Smartphone(s) to cart.\n", quantity);
    } else {
        printf("Not enough stock.\n");
    }
}

// Fungsi melihat isi keranjang
void view_cart() {
    printf("\nItems in your cart:\n");
    if (cart_quantity1 > 0)
        printf("Laptop - Quantity: %d, Price per item: %.2f\n", cart_quantity1, product1_price);
    if (cart_quantity2 > 0)
        printf("Smartphone - Quantity: %d, Price per item: %.2f\n", cart_quantity2, product2_price);
    if (cart_quantity1 == 0 && cart_quantity2 == 0)
        printf("Your cart is empty.\n");
}

// Fungsi menghitung total harga
float calculate_total() {
    return (cart_quantity1 * product1_price) + (cart_quantity2 * product2_price);
}

// Fungsi utama
int main() {
    int choice, product_id, quantity;

    printf("=== Welcome to the Store ===\n");

    do {
        printf("\n1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Menampilkan produk
                printf("\nAvailable Products:\n");
                printf("1. %s - Price: %.2f, Stock: %d\n", product1_name, product1_price, product1_stock);
                printf("2. %s - Price: %.2f, Stock: %d\n", product2_name, product2_price, product2_stock);
                break;

            case 2: // Menambahkan ke keranjang
                printf("\nEnter Product ID (1 for Laptop, 2 for Smartphone): ");
                scanf("%d", &product_id);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                add_to_cart(product_id, quantity);
                break;

            case 3: // Melihat keranjang
                view_cart();
                break;

            case 4: // Checkout
                view_cart();
                printf("\nTotal price: %.2f\n", calculate_total());
                printf("Thank you for shopping with us!\n");
                choice = 5; // Keluar setelah checkout
                break;

            case 5: // Keluar
                printf("Exiting the store. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
