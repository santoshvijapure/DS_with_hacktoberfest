//program for reversing singly linked list for predefined values
#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	int data; 
	struct Node* next; 
}; 

/* Function starts from here*/
static void reverse(struct Node** head_ref) 
{ 
	struct Node* prev = NULL; 
	struct Node* current = *head_ref; 
	struct Node* next = NULL; 
	while (current != NULL) { 
		// Store next 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
} 


void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(struct Node* head) 
{ 
	struct Node* temp = head; 
	while (temp != NULL) { 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 


int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 5); 

	printf("Given linked list\n"); 
	printList(head); 
	reverse(&head); 
	printf("\nReversed Linked list \n"); 
	printList(head); 
	getchar(); 
} 
