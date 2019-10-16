#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct node *front=NULL;
struct node *rear=NULL;
struct node
{
int key;
struct node *addr;
};
void push(int k)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
if(front==NULL)
{
temp->key=k;
temp->addr=NULL;
front=rear=temp;
}
else 
{
temp->addr=NULL;
temp->key=k;
rear->addr=temp;
rear=temp;
}
}
void pop()
{
if(front==NULL)
{
printf("The Stack is empty!!\n");
}
else if(front->addr==NULL)
{
free(front);
front=NULL;
rear=NULL;
}
else
{
struct node *temp;
temp=front;
while(temp->addr!=rear)
{
temp=temp->addr;
}
temp->addr=NULL;
free(rear);
rear=temp;
}
}
void print()
{
if(front==NULL)
{
printf("The Stack is empty!!\n");
}
else
{
printf("The Stack elements are:\n");
struct node *a;
a=front;
while(a!=NULL)
{
printf("%d\n",a->key);
a=a->addr;
}
}
}
void main()
{
int a,k;
while(1)
{
printf("Select your option:\n");
printf("1.Push\n2.Pop\n3.Print elements\n4.exit\n");
scanf("%d",&a);
switch(a)
{
case 1:printf("Enter the element to be pushed into the stack:");
      scanf("%d",&k);
      push(k);
      break;
case 2:pop();
      break;
case 3:print();
      break;
case 4:exit(0);
default: printf("Error!!\n");
}
}
getch();
}


