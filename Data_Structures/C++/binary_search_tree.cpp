/*
Name-Divya Gupta
Algorithm-Binary Search Tree(insertion,search,inorder-traversal)
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
  int value;
  struct node *left,*right;
};
struct node *newn(int val)
{
  struct node *temp=new(node);
  temp->value=val;
  temp->left=temp->right=NULL;
  return temp;
}

struct node *insert(struct node* root,int data)
{
  if(root==NULL)
  return newn(data);
  if(data<root->value)
  root->left=insert(root->left,data);
  else if(data>root->value)
  root->right=insert(root->right,data);
  return root;
}

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->value); 
        inorder(root->right); 
    } 
} 

struct node* search(struct node* root, int key) 
{ 
  if (root == NULL || root->key == key) 
    return root; 
  if (root->key < key) 
    return search(root->right, key); 
  else
  return search(root->left, key); 
} 
int main()
{
  struct node *root = NULL; 
  root = insert(root, 50); 
  insert(root, 23); 
  insert(root, 34); 
  insert(root, 67); 
  insert(root, 12); 
  inorder(root); 
  int n;
  cout<<"Enter number to search = ";
  cin>>n;
  struct node* n=search(root,n);
  if(n==NULL)
  cout<<"number not found"<<endl;
  else
  cout<<"number is found"<<endl;

}