#include <stdio.h>
#include <string.h>

#define MAX 20

int arr[MAX];
int n = 0;

void Create(){
    int i;
    printf("Enter the number of elements in the array (1 to 20): ");
    scanf("%d", &n);
    
    if (n > 0 && n <= MAX){
        printf("Enter the elements of the array: ");
        for(i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        printf("Array created successfully!\n");
    } else {
        printf("Invalid array size!\n");
        n = 0; // Reset n if invalid size
    }
}

void Display(){
    int i;
    if (n > 0){
        printf("The elements of the array are: ");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Array is empty!\n");
    }
}

void Insert(){
    int pos, value, i;
    if (n >= MAX){
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }
    printf("Enter the position where you want to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1){
        printf("Invalid position!\n");
        return;
    }
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    for (i = n; i >= pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    printf("Element inserted successfully!\n");
}

void Search(){
    int value, i, found = 0;
    printf("Enter the value to search: ");
    scanf("%d", &value);
    for (i = 0; i < n; i++){
        if (arr[i] == value){
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Element not found in the array.\n");
    }
}

void Delete(){
    int pos, i;
    if (n == 0){
        printf("Array is empty! Cannot delete elements.\n");
        return;
    }
    printf("Enter the position of the element to delete (1 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n){
        printf("Invalid position!\n");
        return;
    }
    for (i = pos - 1; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Element deleted successfully!\n");
}

int main(){
    int choice;
    char cont[4];
    
    do {
        printf("\nEnter the respective number for the following operation:\n");
        printf("1. Create an array\n");
        printf("2. Display the elements of the array\n");
        printf("3. Insert an element in the array\n");
        printf("4. Search for an element in the array\n");
        printf("5. Delete an element from the array\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3:
                Insert();
                break;
            case 4:
                Search();
                break;
            case 5:
                Delete();
                break;
            default:
                printf("Enter a valid operation!\n");
                break;
        }
        
        printf("If you want to continue the program, please enter 'Yes' or 'yes'. Otherwise, enter any other key to exit: ");
        scanf("%s", cont);
        
    } while (strcmp(cont, "Yes") == 0 || strcmp(cont, "yes") == 0);
    
    return 0;
}

