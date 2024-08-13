#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next; // self referencing pointer
};

// Function to create a new node 

struct Node* createNode(int num){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));	
	newNode -> data = num;
	mewNode -> next = NULL;
	return newNode;
	
}

// Function to insert a node at begining 

void insertAtBeginning(struct Node** head, int data){
	struct Node* newNode = createNode(data);	
	newNode-> next = *head;
	*head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data){
	struct Node* newNode = createNode(data);
	if(*head = NULL){
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	while (temp->next != NULL){
		temp = temp->next;
	}	
	
	temp->next = newNode;
}

// Function to insert a node at the specific position 

void insertAtPosition(struct Node** head, int data, int pos){
	if(pos<1){
		printf("Position should be >=1\n");
		return;
	}
	struct Node* newNode = createNode(data);
	if(position = 1){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	
	struct Node* temp = *head;
	int i;
	for(i=1; temp!= NULL && i< postion-1; i++){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("The previos node is null.\n");
		return;
	}
	
	newNode->next = temp->next;
	temp->next = newNode;
}

//Function to print the linked

void printList(struct Node* head){
	while(head!= NULL){
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}
int main(){
	
	struct Node* head = NULL;
	int choice, data, position;
	
	while(1){
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1: 
        		printf("Enter data to insert at the begining: ");
        		scanf("%d", data);
        		inserAtBeginning(&head,data);
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
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
		}
	}
	
	return 0;
}
