#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void Enqueue(){
    int value;
    if (rear == MAX - 1){
        printf("Queue Overflow! Cannot enqueue more elements.\n");
    } else {
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Element enqueued successfully!\n");
    }
}

void Dequeue(){
    if (front == -1 || front > rear){
        printf("Queue Underflow! Cannot dequeue elements.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front++]);
        if (front > rear) front = rear = -1;  // Reset the queue if empty
    }
}

void Display(){
    int i;
    if (front == -1){
        printf("Queue is empty!\n");
    } else {
        printf("The elements of the queue are: ");
        for(i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void Peek(){
    if (front == -1){
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

int main(){
    int choice;
    char cont[4];
    
    do {
        printf("\nEnter the respective number for the following operation:\n");
        printf("1. Enqueue an element to the queue\n");
        printf("2. Dequeue an element from the queue\n");
        printf("3. Display the elements of the queue\n");
        printf("4. Peek the front element of the queue\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
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

