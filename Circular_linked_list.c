#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
}*start=NULL,*last=NULL,*temp=NULL;
void creation(int item)
{
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=item;
	p->link=NULL;
	last=p;
	if(start==NULL)
	{
		start=p;
		last=p;
	
	
	}
	else
	{
		temp=start;
		while(temp->link!=NULL)
		{
			temp=temp->link;	
		}
		temp->link=p;
		last=p;
		last->link=start;
	}
		last->link=start;
}
void display()
{
	if(start==NULL)
	{
		printf("List is empty");
		return;
	}
	else
	{
		temp=start;
		while(temp->link!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
		printf("%d\n",temp->data);
	}
}
int main()
{
	int item,i,n,selection,position;
	label:
		printf("Enter 1 to create");
		printf("\nEnter 2 to display");
		printf("\nyour selection");
		scanf("%d",&selection);
		if(selection==1)
		{
			
			printf("Enter no. of nodes");
			scanf("%d",&n);
			printf("Enter numbers\n");
			for(i=0;i<n;i++)
			{
				scanf("%d",&item);
				creation(item);
			}
			goto label;
		}
		else if(selection==2)
		{
			display();
			goto label;
		}
}
