// LANGUAGE: c++
// ENV: gcc
// AUTHOR: Manisha Mandal
// GITHUB: https://github.com/Manisha-nitd

#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node* link;
}node;
void insert(node* a[10],int num)
{
	int index;
	index=num%10;
	node* newnode=new node;
	newnode->data=num;
	newnode->link=NULL;
	if(a[index]==NULL)
	{
        a[index]=newnode;
        return;
	}
	node* temp;
	temp=a[index];
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=newnode;
}
void delete1 (node** a, int num)
{
    int index;
	index=num%10;
	if(a[index]==NULL)
	{
	    cout<<"\nThe number to be deleted is not present in the list!\n";
        return;
	}
	node* temp;
	temp=a[index];
	if(num==temp->data)
    {
        a[index]=temp->link;
        delete temp;
        return;
    }
	while(temp->link!=NULL)
    {
      node* temp1=temp;
      temp=temp->link;
       if(temp->data==num)
       {
           temp1->link=temp->link;
           delete temp;
           return;
       }
    }
    cout<<"\nThe number to be deleted is not present in the list!\n";

}
void search(node **a, int num)
{
    int index;
	index=num%10;
	if(a[index]==NULL)
	{
     cout<<"\nThe number not found!!\n";
        return;
	}
	node* temp;
	temp=a[index];
	while(temp!=NULL)
    {
        if(temp->data==num)
        {
            cout<<"\nThe number is found!!\n";
            return;
        }
        temp=temp->link;
    }
    cout<<"\nThe number not found!!\n";
    return;
}
void display(node **a)
{
   cout<<"\nThe HASH TABLE is :\n";
	for(int i=0;i<10;i++)
	{
		node* temp=a[i];
		cout<<endl;
		if(temp==NULL)
            cout<<" NULL";
        else
        {
           while(temp!=NULL)
		{
			cout<<" "<<temp->data;
			temp=temp->link;
		}
        }
	}
}
int main()
{
	int n,num;
	node* a[10];
	for(int i=0;i<10;i++)
		a[i]=NULL;
	int choice;
	while(1)
    {
    cout<<"\nOPERATION ON HASH TABLE ARE:\n";
	cout<<"1.INSERT\n2.SEARCH\n3.DELETE\n4.DISPLAY\n5.EXIT\n";
	cin>>choice;
	switch(choice)
	{
    case 1:
        cout<<"\nEnter the value :";
		cin>>num;
        insert(a,num);
        break;
    case 2:
        cout<<"\nEnter the element to be searched:";
        cin>>num;
        search(a,num);
        break;
    case 3:
        cout<<"\nEnter the element to delete:";
        cin>>num;
        delete1(a,num);
        break;
    case 4:
        display(a);
        break;
    case 5:
        exit(1);
    default:
        cout<<"\nINVALID CHOICE!!";
	}
    }
return 0;
}