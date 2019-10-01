#include<stdio.h>
#include<stdlib.h>

struct node
{
    int exp;
    int coff;
    struct node *next;
};

typedef struct node node;

void insert(node **p,int c,int e)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->coff=c;
    ptr->exp=e;
    
    ptr->next=(*p);
    (*p)=ptr;
}

void traverse(node *p)
{
    if(p==NULL)
    {
        printf("Empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%dx^%d ",p->coff,p->exp);
        p=p->next;
    }
    printf("\n");
}

node *add(node *p1,node *p2)
{
    node *p3=NULL;
    while (p1!=NULL&&p2!=NULL)
    {
        if(p1->exp>p2->exp)
        {
            insert(&p3,p1->coff,p1->exp);
            p1=p1->next;
        }
        else if(p2->exp>p1->exp)
        {
            insert(&p3,p2->coff,p2->exp);
            p2=p2->next;
        }
        else
        {
            insert(&p3,p1->coff + p2->coff,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(p1==NULL)
    {
        while (p2!=NULL)
        {
            insert(&p3,p2->coff,p2->exp);
            p2=p2->next;
        }
    }
    if(p2==NULL)
    {
        while (p1!=NULL)
        {
            insert(&p3,p1->coff,p1->exp);
            p1=p1->next;
        }
    }
    return p3;
}



int main()
{
    node *p1=NULL,*p2=NULL;
    insert(&p1,4,0);
    insert(&p1,3,2);
    insert(&p1,5,3);
    insert(&p1,6,4);
    traverse(p1);
    
    insert(&p2,4,0);
    insert(&p2,4,1);
    insert(&p2,7,3);
    insert(&p2,6,5);
    traverse(p2);

    node *p3=add(p1,p2);

    traverse(p3);
    return 0;
}