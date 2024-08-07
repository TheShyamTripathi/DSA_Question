#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int stack[MAX];
int top = -1;

void Push(){
    int value;
    if (top >= MAX - 1){
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("Element pushed successfully!\n");
    }
}

void Pop(){
    if (top < 0){
        printf("Stack Underflow! Cannot pop elements.\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void Display(){
    int i;
    if (top < 0){
        printf("Stack is empty!\n");
    } else {
        printf("The elements of the stack are: ");
        for(i = 0; i <= top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void Peek(){
    if (top < 0){
        printf("Stack is empty!\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

int main(){
    int choice;
    char cont[4];
    
    do {
        printf("\nEnter the respective number for the following operation:\n");
        printf("1. Push an element onto the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display the elements of the stack\n");
        printf("4. Peek the top element of the stack\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                Peek();
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

