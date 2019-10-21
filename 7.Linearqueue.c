#include<stdio.h>
struct queue
{
    int a[30];
    int front;
    int rear;
};
void enqueue(struct queue *p,int size)
{

    if(p->rear==size-1)
    {
        printf("The queue is full");
    }
    else
    {
        int item;
        printf("Enter the item");
        scanf("%d",&item);
        if(p->rear==-1 && p->front==-1)
        {
            p->front=0;

        }

        p->a[++p->rear]=item;


    }
}
void dequeue(struct queue *p)
{
    if(p->front==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        int item;
        item=p->a[p->front];
        printf("Deleted item=%d",item);
        if(p->rear==p->front)
        {
            p->front=-1;
            p->rear=-1;
        }
        else
        {

            
            p->front++;
        }
    }
}
void display(struct queue *p)
{
    int i;
    if(p->front==-1 && p->rear==-1)
    {
        printf("Queue is empty");
    }
    else
    {

        printf("Queue:");
        for(i=p->front; i<=p->rear; i++)
        {
            printf("%d",p->a[i]);
        }
    }
}

void main()
{
    int size,c,m;
    struct queue q;
    q.front=-1;
    q.rear=-1;
    printf("Enter the size:");
    scanf("%d",&size);
    do
    {
        printf("Enter the choice\n 1.ENQUEUE\n 2.DEQUEUE\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            enqueue(&q,size);
            display(&q);
            break;
        case 2:
            dequeue(&q);
            display(&q);
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("\nDo you want to continue \n1.yes 2.no\n");
        scanf("%d",&m);
    }
    while(m==1);
}
