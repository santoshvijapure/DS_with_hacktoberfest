/ LANGUAGE: c
// ENV: gcc
// AUTHOR: Manisha-nitd
// GITHUB: https://github.com/Manisha-nitd

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
int main()
{
    struct node *head=NULL ,*temp;
    printf("Enter the number of nodes :\n");
    int n;
    scanf("%d",&n);
    while(n)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        if(head==NULL)
        {
            newnode->prev=NULL;
            newnode->next=NULL;
            printf("Enter data :\n");
            scanf("%d",&newnode->data);
            head=newnode;
            temp=head;
        }
         printf("Enter data :\n");
         scanf("%d",&newnode->data);
         newnode->prev=temp;
         newnode->next=NULL;
         temp->next=newnode;
         temp=newnode;
    }
}