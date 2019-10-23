#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node node;

node * create(node *start);
void display(node *start);
node * insertstart(node *start);
void insertend(node *start);
void insertmiddle(node *start, int n);
void deletelast(node *start);
node * deletestart(node *start);
void deletenode(node *start, int val);

void main()
{
    node *start=NULL;

    start=create(start);

	int n, a, val, c, searchval;

	display(start);

    do{

        printf("Enter 1 for inserting a node at the starting.\n");
        printf("Enter 2 for inserting a node at the ending.\n");
        printf("Enter 3 for inserting a node next to the value needed.\n");
        printf("Enter 4 for deleting a node from the beginning.\n");
        printf("Enter 5 for deleting a node from the end.\n");
        printf("Enter 6 for deleting a node containing the value needed.\n");

        scanf("%d", &a);

        switch(a)
        {
            case 2:     insertend(start);

                        printf("After inserting at the end, \n");
                        display(start);
                        break;


            case 1:     start=insertstart(start);

        	            printf("After inserting at the beginning, \n");
        	            display(start);
                        break;


            case 3:     printf("Enter the info part of the node after which you want to add a new node \n");
        	            scanf("%d", &n);

        	            insertmiddle(start,n);

        	            printf("After inserting in the middle, \n");
        	            display(start);
                        break;

            case 4:     start = deletestart(start);

                        printf("After deleting at the beginning, \n");
                        display(start);
                        break;

            case 5:     deletelast(start);

                	    printf("After deleting at the end, \n");
                	    display(start);
                        break;

            case 6:     printf("Enter the info part of the node you want to delete.\n");
                        scanf("%d", &val);

                        deletenode(start, val);

                        printf("After deleting in the middle, \n");
                        display(start);
                        break;

            default:    printf("Invalid Input\n");
                        break;

        }

        printf("Press 1 to perform more operations.\n");
        scanf("%d", &c);

    }while(c==1);

}

node * create(node *start)
{
	node *newnode, *prev=start;
	int n;

	do
	{
		newnode= (node *)malloc(sizeof(node));

		printf("Enter the information part \n");
		scanf("%d", &newnode->info);

		if(start==NULL)
			start=newnode;

		else
			prev->next=newnode;

        newnode->prev=prev;
        newnode->next=start;
        start->prev=newnode;
		prev=newnode;

		printf("Enter 1 if you want more nodes to be added\n");
		scanf("%d", &n);

	}while(n==1);

	return start;
}

void display(node *start)
{
	printf("The linked list is : \n");

    node *temp;
    temp=start;

	do{
		printf("%d\t", start->info);

		start=start->next;
	}while(start!=temp);

    printf("\n");

}

node *insertstart(node *start)
{
    node *newnode, *temp;

    newnode= (node*)malloc(sizeof(node));

    printf("Enter an element at the beginning of the linked list : \n");

    printf("Enter the information part\n");
	scanf("%d", &newnode->info);

    temp=start->prev;
    newnode->prev=start->prev;
    newnode->next=start;
    start->prev=newnode;
    temp->next=newnode;

    return newnode;

}

void insertend(node *start)
{
    node *newnode, *temp;

    temp=start;

    newnode= (node *)malloc(sizeof(node));

    printf("Enter the information part\n");
	scanf("%d", &newnode->info);

    while(start->next!=temp)
        start=start->next;

    newnode->next=temp;
    newnode->prev=start;
    start->next=newnode;
}

void insertmiddle(node *start, int n)
{
    node *newnode, *temp;

	while(start->info!=n)
		start=start->next;

    temp=start->next;

	newnode=(node *)malloc(sizeof(node));

	printf("Enter the information part : \n");
	scanf("%d", &newnode->info);

    temp->prev=newnode;
	newnode->next=temp;
	start->next=newnode;
    newnode->prev=start;
}

void deletelast(node *start)
{
    node *temp, *temp2, *temp3;
    temp=start;

    do {
        start=start->next;
    } while(start->next!=temp);

    temp3=start;
    temp2=start->next;
    temp->prev=start->prev;
    temp3->next=start->next;

    free(start);
}

node * deletestart(node *start)
{
    node *temp1, *temp2;

    temp1=start->next;
    temp2=start->prev;
    temp2->next=temp1;
    temp1->prev=temp2;

    free(start);

    return temp1;
}

void deletenode(node *start, int val)
{
    node *temp1, *temp2;
    while(start->info !=val){
        start = start->next;

    }
    temp1 =start->prev;
    temp2 =start->next;
    temp1->next = start->next;
    temp2->prev = start->prev;
    free(start);

}
