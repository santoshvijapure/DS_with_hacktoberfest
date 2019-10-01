#include<stdio.h>
#include <malloc.h>
struct BST
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct BST node;

node *Findmax(node *st)
{
     node *current = st;
    while (current->right != NULL)
        {current = current->right;}

    return current;
}


node *createNode(int n)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node* insert(node *root,int n)
{
    if(root==NULL)
    {
        root=createNode(n);
    }
    else if(n<root->data)
    {
        root->left=insert(root->left,n);
    }
    else if(n>root->data)
    {
        root->right=insert(root->right,n);
    }
    else if(n==root->data)
    {
        printf("\n Duplicate no.");
        return;
    }
    return root;
}
void inorder(node *root)
{
    if(root==NULL)
    return;
        inorder(root->left);
        printf("-->%d",root->data);
        inorder(root->right);
}

void preorder(node *root)
{
    if(root==NULL)
    return;
        printf("-->%d",root->data);
        preorder(root->left);
        preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
    return;
        postorder(root->left);
        postorder(root->right);
        printf("-->%d",root->data);
}

node* delnum(node *root,int n)
{
    node *temp;
    if(root==NULL)
    {
        printf("no element exists");
    }
    else if(n<root->data)
    {
        root->left=delnum(root->left,n);
    }
    else if(n>root->data)
    {
        root->right=delnum(root->right,n);
    }
    else
    {
       if(root->left&&root->right)
       {
           temp=Findmax(root->left);
           root->data=temp->data;
           root->left=delnum(root->left,root->data);
       }
        else if(root->left==NULL)
            {   temp==root;
                root=root->right;
                free(temp);
            }
            else if(root->right==NULL)
            {   temp==root;
                root=root->left;
                 free(temp);
            }


    }
 return(root);
}
int main()
{
    node *root=NULL;
    int choice;
    int n;
    char ch;
    do
    {
        printf("\nenter 1=insertion,2=preorder,3=inorder,4=postorder,5=deletion  ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("enter no.to be inserted  ");
                scanf("%d",&n);
                root=insert(root,n);
                break;
            }
        case 2:
            {
                printf("PREORDER IS =\n");
                preorder(root);
                break;
            }
        case 3:
            {
                printf("INORDER IS =\n");
                inorder(root);
                break;
            }
        case 4:
            {
                printf("POSTORDER IS =\n");
                postorder(root);
                break;
            }
        case 5:
            {
                printf("element to be deleted  ");
                scanf("%d",&n);
                root=delnum(root,n);
                printf("element is deleted ");
                break;
            }
        }
        printf("\ndo u want to continue(y|n)...  ");
        ch=getche();
    }while(ch=='y'||ch!='n');

return 0;

}
