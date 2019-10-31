#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int info;
	struct Node *next;
};

typedef struct Node NODE;

NODE * create(NODE *start);
void display(NODE *start);
NODE * insertstart(NODE *start);
void insertend(NODE *start);
void insertmiddle(NODE *start, int n);
void deletelast(NODE *start);
NODE * deletestart(NODE *start);
void deletenode(NODE *start, int val);
void search(NODE *start, int val);

void main()
{
	NODE *start=NULL;
	int n, a, val, c, searchval;

	start=create(start);

	display(start);

    do{

        printf("Enter 1 for inserting a node at the starting.\n");
        printf("Enter 2 for inserting a node at the ending.\n");
        printf("Enter 3 for inserting a node next to the value needed.\n");
        printf("Enter 4 for deleting a node from the beginning.\n");
        printf("Enter 5 for deleting a node from the end.\n");
        printf("Enter 6 for deleting a node containing the value needed.\n");
        printf("Enter 7 to search a value in the linked list.\n");

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

            case 7:     printf("Enter the value you want to search.\n");
                        scanf("%d", &searchval);

                        search(start, searchval);
                        break;

        }

        printf("Press 1 to perform more operations.\n");
        scanf("%d", &c);

    }while(c==1);

}

NODE * create(NODE *start)
{
	NODE *newnode, *prev;
	int n;

	do
	{
		newnode= (NODE *)malloc(sizeof(NODE));

		printf("Enter the information part \n");
		scanf("%d", &newnode->info);

		newnode->next=NULL;

		if(start==NULL)
			start=newnode;

		else
			prev->next=newnode;

		prev=newnode;

		printf("Enter 1 if you want more nodes to be added\n");
		scanf("%d", &n);

	}while(n==1);

	return start;
}

void display(NODE *start)
{
	printf("The linked list is : \n");

	while(start!=NULL)
	{
		printf("%d\t", start->info);

		start=start->next;
	}
}

void insertend(NODE *start)
{
	printf("Enter an element at the end of the linked list : \n");

	NODE *newnode;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part\n");
	scanf("%d", &newnode->info);

	while(start->next!=NULL)
		start=start->next;

	start->next=newnode;
	newnode->next=NULL;
}

NODE * insertstart(NODE *start)
{
	printf("Enter an element at the beginning of the linked list : \n");

	NODE *newnode;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part\n");
	scanf("%d", &newnode->info);

	newnode->next=start;
	start=newnode;

	return start;
}

void insertmiddle(NODE *start, int n)
{
	NODE *newnode;

	while(start->info!=n)
		start=start->next;

	newnode=(NODE *)malloc(sizeof(NODE));

	printf("Enter the information part : \n");
	scanf("%d", &newnode->info);

	newnode->next=start->next;
	start->next=newnode;

}

void deletelast(NODE *start)
{
    NODE * temp;
    while(start->next!=NULL)
    {
        temp=start;
        start=start->next;
    }

    temp->next=NULL;
    free(start);
}

NODE * deletestart(NODE *start)
{
    NODE * temp;

    temp=start->next;

    free(start);

    return temp;
}

void deletenode(NODE *start, int val)
{
    NODE * temp;

    while(start->info!=val)
    {
        temp=start;
        start=start->next;
    }

    temp->next=start->next;

    free(start);
}

void search(NODE *start, int val)
{
    while(start!=NULL)
    {
        if(start->info==val)
        {
            printf("Value found.\n");
            return;
        }

        start=start->next;
    }

    printf("Not found.\n");
}
