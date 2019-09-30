
// Program to implement STACK using LINKED LISTS
 
#include<stdio.h>
#include<stdlib.h>
 
struct Node{
int val;
struct Node * next;
}*top,stack,*temp;
 
void stackPush(int element){
temp=(struct Node *)malloc(1*sizeof(struct Node));
if (temp==NULL){
    printf("\nMEMORY OVERFLOW");
    exit(0);
}
else if (top==NULL){
    top =(struct Node *)malloc(1*sizeof(struct Node));
    top->val=element;
    top->next=NULL;
}
else {
    temp->next=top;
    temp->val=element;
    top=temp;
 
}
}
void stackPop(){
if (top==NULL){
    printf("\nMEMORY UNDERFLOW");
    exit(0);
}
else {
    temp=top;
    top=top->next;
    free(temp);
}
}
void stackDisplay(){
temp=top;
if(temp==NULL){
    printf("\nEMPTY STACK");
    exit(0);
}
else{
while (temp!=NULL){
printf("%d->",temp->val);
temp=temp->next;
}
}
}
 
void main(){
top=NULL;
int op,element;
system("clear");
do{
printf("\nSELECT AN OPTION:");
printf("\n1. Push.");
printf("\n2. Pop.");
printf("\n3. Display.");
printf("\n4. EXIT.\n");
scanf("%d",&op);
switch(op){
    case 1:
            system("clear");
            printf("\nEnter the element:");
            scanf("%d",&element);
            stackPush(element);
            break;
 
    case 2:
            system("clear");
            stackPop();
            break;
 
    case 3:
            system("clear");
            stackDisplay();
            break;
 
    case 4:
            exit(0);
 
    default:
            system("clear");break;
}
}while(op!=4);
}
