#include<stdio.h>
#include<stdlib.h>

// Define  the node structure 

struct Node{
	int data;
	struct Node* next;
};

// Function to create a new Node 

struct Node * createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// Fucntion to insert a node at he beginning

void insertAtBeginning(struct Node** head, int data){
	struct Node* n = createNode(data);
	if(*head == NULL){
		n->next = n;
		*head = n;
	} else{
		struct Node* temp = *head;
		while(temp-> next != *head){
			temp = temp->next;
		}
		temp->next = n;
		n->next = *head;
		*head = n;
	}
}

// Function to insert At  the end 

void insertAtEnd(struct Node** head, int data){
	struct Node* n = createNode(data);
	if(*head == NULL){
		n->next = n;
		*head = n;
	} else{
		struct Node* temp = *head;
		while(temp->next != *head){
			temp = temp->next;
		}
		temp->next = n;
		n->next = *head;
	}
}

// Function to insert a node at a specified position 

void insertAtPosition(struct Node** head, int data, int pos){
	if (pos < 1) {
        printf("Position should be >= 1\n");
        return;
    }
    struct Node* n = createNode(data);
    if(*head == NULL){
    	if(pos == 1){
    		n->next = n;
    		*head = n;
		} else{
			printf("Position is beyond the current list length.\n");
		}
		return;
	}
	if(pos == 1){
		struct Node* temp = *head;
		while(temp->next != *head){
			temp = temp->next;
		}
		
		n->next = *head;
		temp->next = n;
		*head = n;
		return;
	}
	struct Node*temp = *head;
	int i;
	for(i =1; temp-> next != NULL && i<pos -1; i++){
		temp = temp->next;
	}
	if (temp->next == *head && pos > 2) {
        printf("Position is beyond the current list length.\n");
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
	if (temp-> next == *head){
		free(temp);
		*head == NULL;
	} else{
		struct Node* last = *head;
		while(last->next != *head){
			last = last->next;
		}
		*head = (*head)->next;
		last->next = *head;
		free(temp);
	}
	
}

// Function to delete a node from the end 
void deleteFromEnd(struct Node** head){
	if(*head == NULL){
		printf("List is empty.\n");
		return;
	}
	struct Node* temp = *head;
	if (temp->next == *head){
		free(temp);
		*head = NULL;
	}
	else{
		struct Node* prev = NULL;
		while(temp-> next != *head){
			prev = temp;
			temp = temp->next;
		}
		prev->next = *head;
		free(temp);
	}
}

// Function to delete a node from a specified postion

void deleteFromPosition(struct Node** head, int pos){
	if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if(pos == 1){
    	deleteFromBeginning(head);
    	return;
	}
	
	struct Node* temp = *head;
	struct Node* prev = NULL;
	int i;
	for(i = 1; temp->next != *head && i<pos; i++){
		prev = temp;
		temp = temp->next;
	}
	if(temp->next == *head && pos >1){
		printf("Position Not Found.\n");
		return;
	}
	prev->next - temp->next;
	free(temp);    
}

// Function to print the circular linekd list 
void printList(struct Node* head){
	if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do{
    	printf("%d -> ", temp->data);
    	temp = temp->next;
	} while(temp!=head);
	printf("(head)\n");
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
