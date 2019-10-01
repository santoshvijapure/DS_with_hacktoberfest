#include<stdio.h>
#include<stdlib.h>
 
#define MAX 5	//Maximum number of elements that can be stored
 
int top=-1,stack[MAX];
//operations to be performed on stack
void push();
void pop();
void display();
 
void main()
{
	int ch;
	
	while(1)	//loop will terminated after entering 4 choice
	{
		printf("\n*** Stack Menu ***");
		printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\n\nEnter your choice(1-4):");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
	}
}
 
void push()
{
	int val;
	
	if(top==MAX-1)
	{
		printf("\nStack is full!!");
	}
	else
	{
		printf("\nEnter Element to Push:");
		scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}
 
void pop()
{
	if(top==-1)
	{
		printf("\nStack is Empty!!");
	}
	else
	{
		printf("\nDeleted Element is %d",stack[top]);
		top=top-1;
	}
}
 
void display()
{
	int i;
	
	if(top==-1)
	{
		printf("\nStack is Empty!!");
	}
	else
	{
		printf("\nStack is...\n");
		for(i=top;i>=0;--i)
			printf("%d\n",stack[i]);
	}
}
