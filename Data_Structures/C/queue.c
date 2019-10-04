#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
int element;
struct Link *next;
}Link;
Link *create_link(int i, Link *nextval){
    Link *n = (Link*) malloc(sizeof(Link));
    n->element = i;
    n->next = nextval;
    return n;
}
Link *create_link2(Link *nextval){
    Link *n = (Link*) malloc(sizeof(Link));
    n->next = nextval;
    return n;
}
typedef struct Queue{
Link *front;
Link *rear;
int size;
}Queue;
Queue *create_queue(){
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->rear=create_link2(NULL);
    q->front=q->rear;
    q->size =0;
    return q;
}
void clear(Queue *q){
    q->rear=create_link2(NULL);
    q->front=q->rear;
    q->size =0;
}
void enqueue(Queue *q, int it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}
int dequeue(Queue *q){
    if(q->size==0) printf("OPAAAAAA\n");
    int it = q->front->next->element;
    q->front->next = q->front->next->next;
    if(q->front->next==NULL){
        q->rear = q->front;
    }
    (q->size)--;
    return it;
}
int frontValue(Queue *q){
    if(q->size==0) printf("OPAAAAA\n");
    return q->front->next->element;
}
int length(Queue *q){
    return q->size;
}
int main(){
    
    Queue *q;
    q = create_queue();
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 80);
    printf("Tamanho: %d\n", length(q));
    printf("deq: %d\n", dequeue(q));
    printf("deq: %d\n", dequeue(q));
    printf("deq: %d\n", dequeue(q));
    printf("Tamanho: %d\n", length(q));

    return 0;
}
