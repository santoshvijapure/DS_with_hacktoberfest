//Language : c++
// ENV: gcc
//Author: Sathyanarayanan R
// GITHUB: https://github.com/rsathya4802
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct LinkedList
{
    int val;
    struct LinkedList* next;
}*start=NULL,*end_list=NULL;
typedef struct LinkedList* pointer;
pointer createNode(int x)
{
    pointer temp=(pointer)malloc(sizeof(struct LinkedList));
    temp->val=x;
    temp->next=NULL;
}
void insert_node(int x)
{
    pointer temp=createNode(x);
    if(start==NULL)
    {
        start=temp;
        end_list=temp;
    }
    else
    {
        end_list->next=temp;
        end_list=end_list->next;
    }
}
void delete_node(int x)
{
    if(start==NULL )
        return ;
    if(start->val==x)
    {
        start=start->next;
        return;
    }
     pointer temp=start;
        pointer del;
    while (temp!=NULL)
    {
        if(temp->next->val==x)
            {
                del=temp->next;
                if(del==end_list)
                    end_list=temp;
                temp->next=del->next;
                delete del;
                return ;
            }
            temp=temp->next;
    }
    cout<<"Element not found\n";
}
void print_all()
{
    pointer temp=start;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        
    }
    else
    {
        cout<<"List is empty\n";
    }
    
    
}
void find_val(int x)
{
    pointer temp=start;
    while (temp!=NULL)
    {
        if(temp->val==x)
            {
                cout<<"Value Found\n";
                return;
            }
            temp=temp->next;
    }
    cout<<"Value not found\n";
}
int main()
{
    int val;
    int ch;
    int cont=1;
    while (cont==1)
    {
        cout<<"1.Insert\n2.Delete\n3.Print\n4.Find Value\n";
        cout<<"Enter Choice: ";
       cin>>ch;
        switch (ch)
        {
        case 1:
        {
            cout<<"Enter value to insert in linked list: ";
            cin>>val;
            insert_node(val);
            print_all();

        };
        break;
        case 2:
        {
            cout<<"Enter value to delete in linked list: ";
            cin>>val;
            delete_node(val);
            print_all();
        };
        break;
        case 3:
        {
            print_all();
        };
        break;
        case 4:
        {
            cout<<"Enter value to find: ";
            cin>>val;
            find_val(val);
        }
        break;
        
        default:
            break;
        }
        cout<<"\n";
        cout<<"Want to continue?  Enter 1: ";
        cin>>cont;
    }
    
    return 0;
}
