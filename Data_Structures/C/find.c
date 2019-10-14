#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data; 
	struct list *next;
	struct list *prev;
}node;

void display(node *temp)
{
	printf("The list is as follows = \n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
	return;
}

int main(){
	node *head=NULL,*temp,*temp1;
	int choice,max;
	
	//Taking the linked list as input
	do
	{
		temp=(node *)malloc(sizeof(node));
		if(temp!=NULL)
		{
			printf("\nEnter the element in the list = ");
			scanf("%d",&temp->data);
			temp->next=NULL;
			if(head==NULL)
			{	
				temp->prev=head;
				temp->next=head;
				head=temp;
			}
			else
			{
				temp1=head;
				while(temp1->next!=NULL)
				{
					temp1=temp1->next;
				}
				temp1->next=temp;
				temp->prev=temp1;
			}
		}
		else
		{
			printf("\nMemory not avilable...node allocation is not possible");
		}
		printf("\nIf you wish to add more data on the list enter 1 = ");
		scanf("%d",&choice);
	}while(choice==1);
	
	display(head);
	
	//finding max
	temp=head;
	max=temp->data;
	while(temp!=NULL)
	{
		if(temp->data>max)
			max=temp->data;
		temp=temp->next;
	}
	printf("\nThe largest element in the list is = %d",max);
	
	return 0;
}
