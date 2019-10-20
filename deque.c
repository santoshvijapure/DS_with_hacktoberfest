#include<stdio.h>
struct deque
{
    int front;
    int rear;
    int q[20];
};
int n;
void inf(struct deque *p)
{
    int it,nxt;
    printf("item:");
    scanf("%d",&it);
    if(p->front==-1 && p->rear==-1)
    {
        p->front=n-1;
        p->rear=n-1;
        p->q[p->front]=it;
        return;
    }
    else if(p->front==0)
    {
        nxt=n-1;
    }
    else
    {
        nxt=p->front-1;
    }
    if(nxt!=p->rear)
    {
        p->front=nxt;
        p->q[p->front]=it;
    }
    else
    {
        if(nxt==p->rear)
        printf("queue is full");
    }
}
void disp(struct deque *p)
{
    if(p->rear==-1 && p->front==-1){
        printf("empty");
        return;
    }
    int i;
    if(p->front<=p->rear){
    for(i=p->front;i<=(p->rear);i++)
    {
        printf("%d ",p->q[i]);
    }
    }
    else
    {
    for(i=p->front;i!=(p->rear);i=(i+1)%n)
    {
        printf("%d ",p->q[i]);
    }
    printf("%d ",p->q[i]);
    }
}
void inr(struct deque *p)
{
    int it,nxt;
    printf("item:");
    scanf("%d",&it);
    if(p->front==-1 && p->rear==-1)
    {
        p->front=0;
        p->rear=0;
        p->q[p->rear]=it;
        return;

    }
    else
    {
        nxt=(p->rear+1)%n;
        if(nxt!=p->front)
        {
            p->rear=nxt;
            p->q[p->rear]=it;
        }
        else
        {
            printf("queue is full");
        }
    }
}
void df(struct deque *p)
{
    int it;
    if(p->front==-1)
    {
        printf("queue empty");
    }
    else
    {
        it=p->q[p->front];
        if(p->front==p->rear)
        {
            p->front=-1;
            p->rear=-1;
        }
        else
        {
            p->front=(p->front+1)%n;
        }

    printf("\nremoved item:%d",it);}
}
void dr(struct deque *p)
{
    int it;
    it=p->q[p->rear];
    if(p->rear==-1)
    {
        printf("queue empty");
        return;
    }
    else
    {
        if(p->rear==p->front)
        {
            p->rear=-1;
            p->front=-1;
        }
        else
        {
            p->rear--;
        }
        printf("removed:%d",it);
}
}


void main()
{
    struct deque p;
    p.rear=-1;
    p.front=-1;
    int ch;
    printf("size:");
    scanf("%d",&n);
    while(1){
    printf("\n1.Insertion at front\n2.insertion at rear\n3.deletion at front\n4.deletion at rear\n5.display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:inf(&p);
        break;
        case 2:inr(&p);
        break;
        case 3:df(&p);
        break;
        case 4:dr(&p);
        break;
        case 5:disp(&p);
        break;
        case 6:return;
    }
    }

}
