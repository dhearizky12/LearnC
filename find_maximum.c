#include <stdio.h>

int main() {
    int arr[5];          // Array to store 5 values
    int *ptr = arr;      // Pointer to access the array
    int max;             // Variable to store the maximum value
    int length = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Prompting the user to enter values
    printf("Enter %d values:\n", length);
    for (int i = 0; i < length; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", ptr + i);  // Using pointer to store the value in the array
    }

    // Finding the maximum value
    max = *ptr;  // Initialize max with the first value
    for (int i = 1; i < length; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);  // Update max if a larger value is found
        }
    }

    // Display the maximum value
    printf("The maximum value is: %d\n", max);

    return 0;
}
