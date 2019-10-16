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
void enqueue(int k)
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
void dequeue()
{
if(front==NULL)
{
printf("The Queue is empty!!\n");
}
else if(front->addr==NULL)
{
free(front);
front=rear=NULL;
}
else
{
struct node *temp;
temp=front->addr;
front->addr=NULL;
free(front);
front=temp;
}
}
void print()
{
if(front==NULL)
{
printf("The Queue is empty!!\n");
}
else
{
printf("The Queue elements are:\n");
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
printf("1.Enqueue\n2.Dequeue\n3.Print elements\n4.exit\n");
scanf("%d",&a);
switch(a)
{
case 1:printf("Enter the element to be enqueued:");
      scanf("%d",&k);
      enqueue(k);
      break;
case 2:dequeue();
      break;
case 3:print();
      break;
case 4:exit(0);
default: printf("Error!!\n");
}
}
getch();
}


