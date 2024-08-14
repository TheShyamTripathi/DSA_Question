#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

// Function to create a new Node 

struct Node* createNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

// Function to insert ta a node at the Beginning
void insertAtBeginning(struct Node** head, int data){
	struct Node* n = createNode(data);
	if(*head != NULL){
		(*head)-> prev = n;
	}
	
	n->next = *head;
	*head = n;
} 

// Function to insert a node at the end

void insertAtEnd(struct Node** head, int data){
	struct Node* n = createNode(data);
	if(*head == NULL){
		*head = n;
		return;
	}
	
	struct Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}

// Function to insert a node at specified position 
void insertAtPosition(struct Node** head, int data, int pos){
	if(pos<1){
		printf("Position should be >=1\n");
		return;
	}
	
	struct Node* n = createNode(data);
	if (pos==1){
		if(*head != NULL){
		(*head)->prev = n;
		}
		n->next = *head;
		*head = n;
		return;

	}
	struct Node* temp = *head;
	int i;
	for(i = 1; temp!=NULL && i<pos-1; i++){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("position is beyond the current list length.\n");
		return;
	}
	n->next = temp->next;
	if(temp->next != NULL){
		temp->next->prev = n;
	}
	temp->next = n;
	n->prev = temp;
}

//  Function to delete a node from the beginning

void deleteFromBeginning(struct Node** head){
	if(*head == NULL){
		printf("List is Empty.\n");
		return;
	}
	struct Node* temp = *head;
	*head = (*head)->next;
	if(*head != NULL){
		(*head)->prev = NULL;
	}
	free(temp);
}

// Function to delete a node from the end 

void deleteFromEnd(struct Node** head){
	if(*head == NULL){
		printf("List is empty.\n");
		return;
	}
	struct Node* temp = *head;
	if(temp->next = NULL){
		free(temp);
		*head = NULL;
		return;
	}
	while(temp->next != NULL){
		temp= temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
}

// Function to delte a node from a sepcified position
void deleteFromPosition(struct Node** head, int pos){
	if(*head == NULL){
		printf("List is empty.\n");
		return;
	}
	struct Node* temp = *head;
	if(pos ==1){
		*head = temp->next;
		if(*head != NULL){
			(*head)->prev = NULL;
		}
		free(temp);
		return;
	}
	int i;
	for(i = 1; temp != NULL && i<pos; i++){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("position Not found.\n");
		return;
	}
	if(temp->next != NULL){
		temp->next->prev = temp->prev;
	}
	if(temp->prev != NULL){
		temp->prev->next = temp->next;
	}
	free(temp);
}

// Function to print the linkedlist from the begining
void printListFromBeginning(struct Node* head){
	while(head != NULL){
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("Null\n");
}

//Function to print the linked list from the end 

void printListFromEnd(struct Node* head){
	if(head == NULL){
		return;
	}
	struct Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	while (temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->prev;
	}
	printf("NUll\n");
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
        printf("7. Print List from Beginning\n");
        printf("8. Print List from End\n");
        printf("9. Exit\n");
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
                printListFromBeginning(head);
                break;
            case 8:
                printListFromEnd(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
