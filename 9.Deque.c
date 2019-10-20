#include<stdio.h>
int size;
struct queue
{
    int a[30];
    int front;
    int rear;
};
void enqueue(struct queue *p)
{   int item;
    printf("Enter the item:");
    scanf("%d",&item);
    if(p->front==-1)
    {
        p->rear=size-1;
        p->front=size-1;
        p->a[p->front]=item;
    }
    else
    {
        int ahead;
        if(p->front==0)
        {
            ahead=size-1;
        }
        else
        {
            ahead=p->front-1;
            p->front=ahead;
            p->a[p->front]=item;
        }
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
        item=p->a[p->rear];
        printf("Deleted item=%d",item);
        if(p->front==p->rear)
        {
            p->front=-1;
            p->rear=-1;
        }
        else
        {
            p->rear=p->rear-1;
        }
    }
}
void display(struct queue *p)
{
    int i;
    printf("Deque");
    if(p->front>p->rear)
    {
        for(i=p->front;i<=size-1;i++)
            printf("%d",p->a[i]);
        for(i=0;i<p->rear;i++)
            printf("%d",p->a[i]);
    }
    else
    {
        for(i=p->front; i<=p->rear; i++)
        {
            printf("%d ",p->a[i]);
        }
        printf("\n");
    }
}
void main()
{
    int ch,t=1;
    struct queue q;
    q.front=-1;
    q.rear=-1;
    printf("Enter the size:");
    scanf("%d",&size);
    while(t==1)
    {
        printf("Enter the choice\n 1.ENQUEUE\n 2.DEQUEUE\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            enqueue(&q);
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
        scanf("%d",&t);
    }
    
}
