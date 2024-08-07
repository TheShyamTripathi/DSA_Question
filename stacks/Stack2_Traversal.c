#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack *stack, int num) {
    if (isFull(stack)) {
        printf("The Stack is overflow\n");
        return;
    }
    stack->arr[++stack->top] = num;
    printf("The number %d pushed successfully!\n", num);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("The Stack is underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("The Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("The Stack is empty!\n");
        return;
    }
    int i;
    printf("The elements in the stack are:\n");
    for (i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position in the stack
void addToPosition(struct Stack *stack, int num, int pos) {
    if (isFull(stack)) {
        printf("The Stack is overflow\n");
        return;
    }
    if (pos < 0 || pos > stack->top + 1) {
        printf("Invalid position!\n");
        return;
    }
	int i;
    for ( i = stack->top; i >= pos; i--) {
        stack->arr[i + 1] = stack->arr[i];
    }

    stack->arr[pos] = num;
    stack->top++;
    printf("Pushed %d at position %d\n", num, pos);
}

// Function to delete an element at a specific position in the stack
int deleteElementAtPosition(struct Stack *stack, int pos) {
    if (isEmpty(stack)) {
        printf("The Stack is empty!\n");
        return -1;
    }
    if (pos < 0 || pos > stack->top) {
        printf("Invalid position!\n");
        return -1;
    }

    int deletedElement = stack->arr[pos];
    int i;
    for ( i = pos; i < stack->top; i++) {
        stack->arr[i] = stack->arr[i + 1];
    }

    stack->top--;
    printf("Deleted element %d at position %d\n", deletedElement, pos);
    return deletedElement;
}

// Function to delete a specific element from the stack
void deleteElement(struct Stack *stack, int num) {
    int i, pos = -1;

    for ( i = 0; i <= stack->top; i++) {
        if (stack->arr[i] == num) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Element %d not found in the stack!\n", num);
    } else {
        deleteElementAtPosition(stack, pos);
    }
}

// Main function with a menu-driven interface
int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, num, pos;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Add at specific position\n");
        printf("6. Delete element\n");
        printf("7. Delete element at specific position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to push: ");
                scanf("%d", &num);
                push(&stack, num);
                break;
            case 2:
                num = pop(&stack);
                if (num != -1) {
                    printf("Popped element is %d\n", num);
                }
                break;
            case 3:
                num = peek(&stack);
                if (num != -1) {
                    printf("Top element is %d\n", num);
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Enter the number to add: ");
                scanf("%d", &num);
                printf("Enter the position to add the number: ");
                scanf("%d", &pos);
                addToPosition(&stack, num, pos);
                break;
            case 6:
                printf("Enter the element to delete: ");
                scanf("%d", &num);
                deleteElement(&stack, num);
                break;
            case 7:
                printf("Enter the position to delete the element from: ");
                scanf("%d", &pos);
                deleteElementAtPosition(&stack, pos);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

