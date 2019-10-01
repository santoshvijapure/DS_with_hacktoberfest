// LANGUAGE: c++
// ENV: gcc
// AUTHOR: Nitin Sultania
// GITHUB: https://github.com/nitinsultania

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void insert(node **head,int n)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=n;
    ptr->next=(*head);
    (*head)=ptr;
}

void insert_end(node **head,int n)
{
    node *ptr=(node *)malloc(sizeof(node *));
    ptr->data=n;
    ptr->next=NULL;
    if(*head==NULL)
    {
        (*head)=ptr;
        return;
    }
    node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
}

void insert_pos(node **head,int n,int pos)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=n;
    
    if(head==NULL && pos!=1)
    {
        return;
    }

    node *temp=*head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
            return;
    }

    if(pos!=1 && (*head)!=NULL)
    {
        ptr->next=temp->next;
        temp->next=ptr;
    }
    else
    {
        ptr->next=*head;
        *head=ptr;
    }
    
}

void insert_after(node *head,int ele,int n)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=n;
    if(head==NULL)
        return;
    node *temp=head;
    while(temp!=NULL && temp->data!=ele)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}

void delete(node **head)
{
    if((*head)==NULL)
    {
        printf("No elements");
        return;
    }
    node *ptr=*head;
    (*head)=(*head)->next;
    free(ptr);
}

void delete_end(node **head)
{
    if(*head==NULL)
        return;
    node *temp=*head,*pre;
    if((*head)->next==NULL)
    {
        *head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL)
    {
        pre=temp;
        temp=temp->next;
    }
    free(temp);
    pre->next=NULL;
}

void traverse(node *head)
{
    node *ptr=head;
    if(ptr==NULL)
    {
        printf("No elements");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    node *head1=NULL;
    insert_end(&head1,2);
    insert_end(&head1,5);
    insert_pos(&head,10,1);
    insert_after(head,10,5);
    insert_after(head,16,8);
    delete_end(&head);
    traverse(head);
    delete(&head);
    delete(&head);
    traverse(head);
    return 0;
}