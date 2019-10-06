// LANGUAGE: C
// ENV: gcc
// AUTHOR: Jaswanth K
// GITHUB: https://github.com/JazzKriss21

#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int value;    
    char color;  
    struct node *left, *right, *parent;
};
 
void LeftRotate(struct node **root,struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
 
    if (x->right != NULL)
        x->right->parent = x;

    y->parent = x->parent;
 
    if (x->parent == NULL)
        (*root) = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else    x->parent->right = y;

    y->left = x;
    x->parent = y;
}
 
void rightRotate(struct node **root,struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}
void insertFixUp(struct node **root,struct node *z)
{
    while (z != *root && z->parent->color == 'R')
    {
        struct node *y;
 
        if (z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;
 
        if (y->color == 'R')
        {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        }
 
        else
        {
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent->parent);
            }
 
            if (z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent->parent);
            }
 
            if (z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }
 
            if (z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';
}

void insert(struct node **root, int value)
{
    struct node *z = (struct node*)malloc(sizeof(struct node));
    z->value = value;
    z->left = z->right = z->parent = NULL;
 
    if (*root == NULL)
    {
        z->color = 'B';
        (*root) = z;
    }
    else
    {
        struct node *y = NULL;
        struct node *x = (*root);
 
        while (x != NULL)
        {
            y = x;
            if (z->value < x->value)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (z->value > y->value)
            y->right = z;
        else
            y->left = z;
        z->color = 'R';
 
        insertFixUp(root,z);
    }
}
 
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}
 
int main()
{
    struct node *root = NULL;
    insert(&root,15);
    insert(&root,41);
    insert(&root,22;
    insert(&root,50);
    insert(&root,33);
    insert(&root,28);
    insert(&root,11);
    insert(&root,37);
    printf("inorder Traversal Is : ");
    inorder(root);
 
    return 0;
}