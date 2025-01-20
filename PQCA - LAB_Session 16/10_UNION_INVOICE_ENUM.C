#include <stdio.h>
#include <string.h>

// Definisi enum untuk tipe invoice
typedef enum {
    PRODUCT,
    SERVICE
} InvoiceType;

// Definisi struct untuk produk
typedef struct {
    char productName[30];
    int quantity;
    float pricePerUnit;
} Product;

// Definisi struct untuk jasa
typedef struct {
    char serviceName[30];
    int hours;
    float ratePerHour;
} Service;

// Definisi union untuk invoice
typedef union {
    Product product;
    Service service;
} InvoiceDetails;

// Definisi struct untuk menyimpan informasi invoice
typedef struct {
    char customerName[30];
    InvoiceDetails details;
    InvoiceType invoiceType; // Menggunakan enum untuk tipe invoice
} Invoice;

int main() 
{
    Invoice invoice1;

    // Input customer name
    printf("Enter customer name: ");
    fgets(invoice1.customerName, sizeof(invoice1.customerName), stdin);
    invoice1.customerName[strcspn(invoice1.customerName, "\n")] = '\0'; // remove newline character

    // Choose invoice type
    printf("Choose invoice type (0 for Product, 1 for Service): ");
    scanf("%d", (int*)&invoice1.invoiceType);

    if (invoice1.invoiceType == PRODUCT) 
    {
        // Input product details
        printf("Enter product name: ");
        scanf("%s", invoice1.details.product.productName);
        printf("Enter quantity: ");
        scanf("%d", &invoice1.details.product.quantity);
        printf("Enter price per unit: ");
        scanf("%f", &invoice1.details.product.pricePerUnit);
    } 
    else if (invoice1.invoiceType == SERVICE) 
    {
        // Input service details
        printf("Enter service name: ");
        scanf("%s", invoice1.details.service.serviceName);
        printf("Enter hours: ");
        scanf("%d", &invoice1.details.service.hours);
        printf("Enter rate per hour: ");
        scanf("%f", &invoice1.details.service.ratePerHour);
    } 
    else 
    {
        printf("Invalid invoice type\n");
        return 1;
    }

    // Output invoice details
    printf("\nCustomer Name: %s\n", invoice1.customerName);

    if (invoice1.invoiceType == PRODUCT) 
    {
        printf("Invoice Type: Product\n");
        printf("Product Name: %s\n", invoice1.details.product.productName);
        printf("Quantity: %d\n", invoice1.details.product.quantity);
        printf("Price per Unit: %.2f\n", invoice1.details.product.pricePerUnit);
        printf("Total Price: %.2f\n", invoice1.details.product.quantity * invoice1.details.product.pricePerUnit);
    } 
    else 
    {
        printf("Invoice Type: Service\n");
        printf("Service Name: %s\n", invoice1.details.service.serviceName);
        printf("Hours: %d\n", invoice1.details.service.hours);
        printf("Rate per Hour: %.2f\n", invoice1.details.service.ratePerHour);
        printf("Total Price: %.2f\n", invoice1.details.service.hours * invoice1.details.service.ratePerHour);
    }

    return 0;
}