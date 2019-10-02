/*
This file all the basics things to understand linked list...
It is easy to understand because it is a menu-driven program...
Happy Coding

author: jignesh1604
*/

#include <bits/stdc++.h>
using namespace std;
typedef struct node node;
struct node
{
    int data;
    node *next;

};
void rinsert(node* first)
{
    while(first->next!=NULL&&first!=NULL)
    {
        first=first->next;
    }
    node *temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    cin>>temp->data;


}
void minsert(node *first,int pos)
{
    int i=0;
    while(i!=pos-2)
    {
        first=first->next;
        i++;
    }
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->next=first->next;
    cout<<"Enter the data:\n";
    cin>>temp->data;
    first->next=temp;
}
void finsert(node **add)
{
    node *temp=(node *)malloc(sizeof(node));
    cout<<"Enter the data:";
    cin>>temp->data;
    temp->next=(*add);
    (*add)=temp;

}
void rdelete(node *first)
{
    while((first->next)->next!=NULL)
    {
        first=first->next;
    }
    first->next=NULL;
}
void mdelete(node *first,int pos)
{
    int i=0;
    while(i!=pos-2)
    {
        first=first->next;
        i++;
    }
    first->next=(first->next)->next;
}
void fdelete(node **first)
{
    (*first)=(*first)->next;
}
void display(node *first)
{
    while(first!=NULL)
    {
        cout<<first->data<<" ";
        first=first->next;
    }
}
int main()
{
    int n;
    node *first;
    first=NULL;
    // cout<<"Enter the data for first block:";
    // cin>>first->data;
    // first->next=NULL;
    z:
    cout<<"1:Rear insert\n2:Middle insert\n3:Front insert\n4:Rear deletion\n5:Middle deletion\n6:Front deletion\n7:Display\n";
    cout<<"Enter the number which operation you want to perform\n";

    cin>>n;
    switch(n) {
        case 1: {
            cout << "Enter the data:";
            rinsert(first);
            goto z;
        }
        case 2: {
            int pos;

            cout << "Enter the position:";
            cin >> pos;
            minsert(first, pos);
            goto z;

        }
        case 3: {
            finsert(&first);
            goto z;
        }
        case 4: {
            rdelete(first);
            goto z;
        }
        case 5:
        {
            int pos;
            cout<<"Enter the position:";
            cin>>pos;
            mdelete(first,pos);
            goto z;
        }
        case 6:
        {
            fdelete(&first);
            goto z;
        }
        case 7:
        {
            display(first);
            break;
        }
        default:
        {
            cout<<"Enter a valid option\n";
            goto z;
        }

    }
}
