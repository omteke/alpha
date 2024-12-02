#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct 
{
    char name[NAME_LENGTH];
    double price;
    int quantity;
} Product;

void insertProduct(Product products[], int *count)
 {
    if (*count >= MAX_PRODUCTS) 
	{
        printf("Product list is full!\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[*count].name);

    printf("Enter product price: ");
    scanf("%lf", &products[*count].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);

    (*count)++;
}

void deleteProduct(Product products[], int *count) {
    if (*count == 0) {
        printf("Product list is empty!\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the product to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            break;
        }
    }

    if (i == *count) {
        printf("Product not found!\n");
    } else {
        for (int j = i; j < *count - 1; j++) {
            products[j] = products[j + 1];
        }
        (*count)--;
        printf("Product deleted successfully!\n");
    }
}

void searchProduct(const Product products[], int count) {
    if (count == 0) {
        printf("Product list is empty!\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the product to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\nProduct found:\n");
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);
            return;
        }
    }
    printf("Product not found!\n");
}

void displayProducts(const Product products[], int count) {
    if (count == 0) {
        printf("No products to display!\n");
        return;
    }

    printf("\nProduct List:\n");
    printf("------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Price", "Quantity");
    printf("------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.2f %-10d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n1. Insert Product\n");
        printf("2. Delete Product\n");
        printf("3. Search Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertProduct(products, &count);
                break;
            case 2:
                deleteProduct(products, &count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                displayProducts(products, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

