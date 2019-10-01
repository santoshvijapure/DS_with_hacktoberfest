// LANGUAGE: C++
// ENV: gcc
//AUTHOR: Proma Roy
//GITHUB: https://github.com/promaroy

//implementing stack with linked list....

#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node *next;
} *top=NULL;
void push(int data)//insert an element
{
  struct node *p=new node();// node created
  p->data=data;
  if(top==NULL)// incase of empty stack
  {
    p->next=NULL;
    top=p;

  }
  else
  {
    p->next=top;
    top=p;
  }
}
void pop() // delete an element
{
  struct node * t;
  t=top;
  top=top->next;
  free(t);
}
void head()// display the top element
{
  cout<<top->data<<endl;
}
void display()// display elements of stack
{
  struct node * tmp=top;
  while(tmp!=NULL)
  {
    cout<<tmp->data<<" ";
    tmp=tmp->next;
  }
  cout<<endl;
}
void empty()// to check stack is empty
{
  if(top==NULL)
  {
    cout<<"stack is empty"<<endl;
  }
  else
  {
    cout<<"Not empty"<<endl;
  }
}
int main()
{
  push(1);
  push(2);
  push(3);
  pop();
  top();
  empty();
}
