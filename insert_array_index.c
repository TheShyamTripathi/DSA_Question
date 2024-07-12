#include <stdio.h>

int main() {
    int n, position, value;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n + 1];  // Create an array with one extra space for the new element

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position where you want to insert the element (0-indexed): ");
    scanf("%d", &position);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    // Shift elements to the right from position to end
    for (int i = n; i > position; --i) {
        arr[i] = arr[i - 1];
    }

    // Insert the value at the specified position
    arr[position] = value;

    // Print the updated array
    printf("Updated array after insertion:\n");
    for (int i = 0; i < n + 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
