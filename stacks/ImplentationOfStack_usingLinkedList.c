#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

struct node* Top = NULL;

// push operation
void push(int num) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = num;
    n->next = Top;
    Top = n;
    printf("\nPushed Successfully\n");
}

// Pop operation
void pop() {
    struct node* t;
    if (Top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        t = Top;
        printf("\n%d", Top->data);
        Top = Top->next;
        free(t);
    }
}

// Display Operation
void display() {
    struct node* t;
    if (Top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("\nElements in the stack are: ");
        for (t = Top; t != NULL; t = t->next) {
            printf("\t%d", t->data);
        }
        printf("\n");
    }
}

// Peek operation 
void peek() {
    if (Top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("\nTop element: %d\n", Top->data);
    }
}

int main() {
    int num, op;

    char y[4];

    do {
        printf("Enter the operation to execute\n 1. push \n2. pop \n3. display \n4. peek: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nEnter the number to push: ");
                scanf("%d", &num);
                push(num);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;
        }

        printf("\nEnter Yes to continue or any key to exit: ");
        scanf("%3s", y); 
    } while (strcmp(y, "yes") == 0 || strcmp(y, "Yes") == 0);

    return 0;
}
