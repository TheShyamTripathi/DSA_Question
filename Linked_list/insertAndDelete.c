#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

// Function to create a new Node

struct Node* createNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	return n;
}

// Function to insert at Begining

void insertAtBeginning(struct Node** head, int data){
	struct Node* n = createNode(data);
	n->next = *head;
	*head = n;
}

// Function to insert at End
void insertAtEnd(struct Node** head, int data){
	struct Node* n = createNode(data);
	if(*head = NULL){
		*head = n;
		return;
	}
	
	struct Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
}

// Function to insert at specific position

void insertAtPosition(struct Node** head, int data, int pos){
	if(pos < 1){
		printf("Position should be >= 1\n");
		return;
	}
	struct Node* n = createNode(data);
	if(pos == 1){
		n->next = *head;
		*head = n;
		return;
	}
	
	struct Node* temp = *head;
	int i;
	for(i=1; temp!= NULL && i<pos-1; i++){
		temp= temp->next;
	}
	
	if(temp == NULL){
		printf("The previous node is null.\n");
		return;
	}
	
	n->next = temp->next;
	temp->next = n;
}

// Function to delete a node from the beginning

void deleteFromBeginning(struct Node** head){
	if(*head == NULL){
		printf("List is empty.\n");
		return;
	}
	
	struct Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

// Function to delete a node from the end

void deleteFromEnd(struct Node** head){
	if(*head == NULL){
		printf("List is empty.\n");
		return;
	}
	
	struct Node* temp = *head;
	if(temp->next == NULL){
		free(temp);
		*head = NULL;
		return;
	}	
	while(temp->next->next != NULL){
		temp= temp->next;
	}
	
	free(temp->next);
	temp->next = NULL;
}

// Function to delete a node from the specifed position

void deleteFromPosition(struct Node** head, int pos){
	if(*head == NULL){
		printf("List is Empty.\n");
		return;
	}
	struct Node* temp = *head;
	if(pos == 1){
		*head = temp->next;
		free(temp);
		return;
	}
	int i;
	for(i=1; temp!= NULL && i<pos -1;i++){
		temp = temp->next;
	}
	if(temp == NULL || temp->next == NULL){
		printf("position not found.\n");
		return;
	}
	
	struct Node* next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

// Function to print the linked list

void printList(struct Node* head){
	while(head!= NULL){
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert the data: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position to delete the data: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                printList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
