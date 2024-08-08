#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
    int size;
};

void initQueue(struct Queue *queue){
	queue->front = -1;
	queue->rear = -1;
	queue->size = 0;
}

int isEmpty(struct Queue *queue){
	return queue->size == 0;
}

int isFull(struct Queue *queue){
	return queue->size == MAX;
}

void enqueue(struct Queue *queue, int num){
	if(isFull(queue)){
		printf("The Queue is full\n");
		return;
	}
	
	if(queue->rear== MAX-1){
		queue->rear = -1;
	}
	
	queue->arr[++queue->rear]= num;
	if(queue->front ==-1){
		queue->front =0;
	}
	queue->size++;
	printf("Enqueued %d successfully!\n", num);
}

int dequeue(struct Queue *queue){
	if (isEmpty(queue)) {
        printf("The Queue is empty\n");
        return -1;
    }
    int num = queue->arr[queue->front++];
    if(queue->front==MAX){
    	queue ->front =0;
	}
	
	queue->size--;
	return num;
}

int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("The Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(struct Queue *queue){
	if (isEmpty(queue)) {
        printf("The Queue is empty\n");
        return;
    }
    
    int i;
    printf("The elements in the queue are:\n");
    for(i=0; i<queue->size; i++){
    	int index = (queue->front +i)%MAX;
    	printf("%d ", queue->arr[index]);
	}
	printf("\n");
}

// Function to insert the elements at specific position in the queue
void addToPosition(struct Queue *queue, int num, int pos){
	    if (isFull(queue)) {
        printf("The Queue is full\n");
        return;
    }
    if (pos < 0 || pos > queue->size) {
        printf("Invalid position!\n");
        return;
    }
    int i;
    for(i = queue->size; i>pos;i--){
    	int from = (queue -> front +i -1) % MAX;
    	int to = (queue->front +i) % MAX;
    	queue ->arr[to] = queue -> arr[from];
	}
	
	int index = (queue -> front + pos) %MAX;
	queue ->arr[index] = num;
	if(queue ->rear = MAX-1){
		queue->rear = -1;
	}
	queue->rear = (queue->rear +1)% MAX;
	queue ->size++;
	printf("Added %d at position %d\n",num,pos);
}

// Function to delete Element at a specific position in the queue

int deleteElementAtPosition(struct Queue *queue, int pos){
	    if (isEmpty(queue)) {
        printf("The Queue is empty\n");
        return -1;
    }
    	if (pos < 0 || pos >= queue->size) {
        	printf("Invalid position!\n");
        	return -1;
    	}
    	
    	int index = (queue->front + pos) % MAX ;
    	int deletedElement = queue->arr[index];
    	int i;
    	for( i = pos; i < queue->size-1; i++){
    		int from = (queue->front + i+1)% MAX;
    		queue->arr[index] = queue->arr[from];
    		index = from;
		}
		
		if(queue -> rear == 0){
			queue->rear = MAX;
		}
		
		queue->rear = (queue->rear-1)% MAX;
		queue -> size--;
		printf("Deleted element %d at position %d\n", deletedElement, pos);
		return deletedElement;
}

int deleteElement(struct Queue *queue, int num){
	int i, pos = -1;
	
	for(i=0; i< queue->size; i++){
		int index = (queue->front +i)% MAX;
		if(queue -> arr[index]==num){
			pos = i;
			break;
		}
	}
	
	if (pos == -1){
		printf("Element %d not found in the queue!\n", num);
		
	} else {
		deleteElementAtPosition(queue,pos);
	}
}

int main(){
    struct Queue queue;
    initQueue(&queue);

    int choice, num, pos;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
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
                printf("Enter the number to enqueue: ");
                scanf("%d", &num);
                enqueue(&queue, num);
                break;
            case 2:
                num = dequeue(&queue);
                if (num != -1) {
                    printf("Dequeued element is %d\n", num);
                }
                break;
            case 3:
                num = peek(&queue);
                if (num != -1) {
                    printf("Front element is %d\n", num);
                }
                break;
            case 4:
                display(&queue);
                break;
            case 5:
                printf("Enter the number to add: ");
                scanf("%d", &num);
                printf("Enter the position to add the number: ");
                scanf("%d", &pos);
                addToPosition(&queue, num, pos);
                break;
            case 6:
                printf("Enter the element to delete: ");
                scanf("%d", &num);
                deleteElement(&queue, num);
                break;
            case 7:
                printf("Enter the position to delete the element from: ");
                scanf("%d", &pos);
                deleteElementAtPosition(&queue, pos);
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


