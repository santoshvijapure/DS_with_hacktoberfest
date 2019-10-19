#include<stdio.h>
struct q
{
    int front;
    int rear;
    int Q[10];
};
int size;
void enq(struct q *p)
{
    int el;
    printf("enter element:");
    scanf("%d",&el);
    if(p->rear==size-1)
    {
        printf("queue is full");
    }
    else
    {
        if(p->rear==-1 && p->front==-1)
        {
            p->front=0;
        }
        p->rear++;
        p->Q[p->rear]=el;
    }
disp(&p);
}

void deq(struct q *p)
{
    int it;
    if(p->front==-1 && p->rear==-1)
    {
        printf("array is empty");
    }
    else
    {
        it=p->Q[p->front];
        if(p->front == p->rear)
        {
            p->front=-1;
            p->rear=-1;
        }
        else
        {
            p->front++;
        }
        printf("removed:%d",it);

    }
}

void disp(struct q *p)
{
    int i;
    for(i=p->front;i<=p->rear;i++)
    {
        printf("%d",p->Q[i]);
    }
}




void main()
{
    struct q p;
    int ch;
    p.rear=-1;
    p.front=-1;

    scanf("%d",&size);
    while(1){
    printf("enter choice:");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:enq(&p);
            break;
    case 2:deq(&p);
            break;
    case 3:disp(&p);
            break;
    }}}
