#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

struct node* Front = NULL;
struct node* Rear = NULL;

// Enqueue operation
void enqueue(int num) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = num;
    n->next = NULL;

    if (Front == NULL) {
        Front = n;
        Rear = n;
    } else {
        Rear->next = n;
        Rear = n;
    }

    printf("\nEnqueued Successfully\n");
}

// Dequeue operation
void dequeue() {
    struct node* t;
    if (Front == NULL) {
        printf("\nQueue Underflow\n");
    } else {
        t = Front;
        printf("\nDequeued element: %d\n", Front->data);
        Front = Front->next;
        free(t);
        if (Front == NULL) {
            Rear = NULL;
        }
    }
}

// Display operation
void display() {
    struct node* t;
    if (Front == NULL) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nElements in the queue are: ");
        for (t = Front; t != NULL; t = t->next) {
            printf("\t%d", t->data);
        }
        printf("\n");
    }
}

// Peek operation
void peek() {
    if (Front == NULL) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nFront element: %d\n", Front->data);
    }
}

int main() {
    int num, op;

    char y[4];

    do {
        printf("Enter the operation to execute\n 1. enqueue \n2. dequeue \n3. display \n4. peek: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nEnter the number to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;

            case 2:
                dequeue();
                break;
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
