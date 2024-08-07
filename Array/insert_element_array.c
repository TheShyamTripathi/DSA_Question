#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n + 1];  // Create an array with one extra space for the new element

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int value;
    printf("Enter the value to add at the last position: ");
    scanf("%d", &value);

    arr[n] = value;  // Add the value at the last position

    // Print the updated array
    printf("Updated array after adding element at last position:\n");
    for (int i = 0; i < n + 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
