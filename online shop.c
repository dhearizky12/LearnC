#include <stdio.h>
#include <string.h>

// Struktur untuk Product
typedef struct {
    char name[50];
    double price;
    int quantity; // Jumlah yang diminta pengguna
} Product;

// Fungsi untuk menampilkan informasi produk
void displayProductInformation(Product *product) {
    double totalPrice = product->price * product->quantity;
    printf("Name : %s\n", product->name);
    printf("Price : %.2f\n", product->price);
    printf("Quantity : %d\n", product->quantity);
    printf("Total Price : %.2f\n", totalPrice);
    printf("******************************\n");
}

// Struktur untuk Warehouse
typedef struct {
    Product product;
    int stock_quantity; // Stok di warehouse
} Warehouse;

// Fungsi untuk menampilkan stok warehouse
void displayWarehouseStock(Warehouse *warehouse) {
    printf("=========== Warehouse Stock =============\n");
    printf("Product Name : %s\n", warehouse->product.name);
    printf("Product stock : %d\n", warehouse->stock_quantity);
}

// Struktur untuk ShoppingCart
typedef struct {
    Product cart_items[100];
    int quantities[100];
    int itemCount;
} ShoppingCart;

// Fungsi untuk inisialisasi ShoppingCart
void initShoppingCart(ShoppingCart *cart) {
    cart->itemCount = 0;
}

// Fungsi untuk menambahkan produk ke ShoppingCart
void addItemToCart(ShoppingCart *cart, Product *product, Warehouse *warehouse) {
    if (warehouse->stock_quantity < product->quantity) {
        printf("Warning: Stok %s di warehouse kurang dari permintaan.\n", product->name);
        return;
    }

    int quantityToAdd = product->quantity < warehouse->stock_quantity ? product->quantity : warehouse->stock_quantity;
    cart->cart_items[cart->itemCount] = *product;
    cart->quantities[cart->itemCount] = quantityToAdd;
    cart->itemCount++;
    
    warehouse->stock_quantity -= quantityToAdd;
    product->quantity -= quantityToAdd;

    printf("Added %d %s(s) to cart.\n", quantityToAdd, product->name);
}

// Fungsi untuk menampilkan isi ShoppingCart
void viewCart(ShoppingCart *cart) {
    if (cart->itemCount == 0) {
        printf("Cart is empty.\n");
    } else {
        printf("============= Cart items : ======================\n");
        for (int i = 0; i < cart->itemCount; i++) {
            printf("%s - Quantity : %d\n", cart->cart_items[i].name, cart->quantities[i]);
        }
    }
}

// Fungsi untuk menghitung total harga di ShoppingCart
double getTotalPrice(ShoppingCart *cart) {
    double total = 0;
    for (int i = 0; i < cart->itemCount; i++) {
        total += cart->cart_items[i].price * cart->quantities[i];
    }
    return total;
}

// Struktur untuk Customer
typedef struct {
    char name[50];
    char username[50];
    char email[50];
    ShoppingCart shoppingCart;
} Customer;

// Fungsi untuk checkout
void checkout(Customer *customer) {
    double totalPrice = getTotalPrice(&customer->shoppingCart);
    printf("Total harga : %.2f\n", totalPrice);
    printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");

    // Clear shopping cart
    customer->shoppingCart.itemCount = 0;
}

int main() {
    // Inisialisasi produk
    Product baju_wanita = {"Baju Wanita", 200000, 3};
    displayProductInformation(&baju_wanita);
    Product baju_pria = {"Baju Pria", 250000, 2};
    displayProductInformation(&baju_pria);
    Product baju_anak = {"Baju Anak", 150000, 10};
    displayProductInformation(&baju_anak);

    // Membuat warehouse
    Warehouse warehouse_A = {baju_wanita, 10};
    Warehouse warehouse_B = {baju_pria, 5};
    Warehouse warehouse_C = {baju_anak, 20};

    displayWarehouseStock(&warehouse_A);
    displayWarehouseStock(&warehouse_B);
    displayWarehouseStock(&warehouse_C);

    // Membuat customer
    Customer customer = {"Dhea Fiky", "dhea_rizky", "email@example.com"};
    initShoppingCart(&customer.shoppingCart);

    // Menambahkan produk ke keranjang belanja customer
    printf("\n*************============*****************\n");
    addItemToCart(&customer.shoppingCart, &baju_wanita, &warehouse_A);
    addItemToCart(&customer.shoppingCart, &baju_pria, &warehouse_B);
    addItemToCart(&customer.shoppingCart, &baju_anak, &warehouse_C);
    printf("\n*************============*****************\n");

    // Menampilkan isi keranjang belanja
    viewCart(&customer.shoppingCart);

    // Checkout dan tampilkan total harga
    checkout(&customer);

    displayWarehouseStock(&warehouse_A);
    displayWarehouseStock(&warehouse_B);
    displayWarehouseStock(&warehouse_C);

    return 0;
}
