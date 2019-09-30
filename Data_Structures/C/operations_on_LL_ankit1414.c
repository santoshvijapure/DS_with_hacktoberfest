#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int rollno;
	char name[20];
	struct node * next;

};


struct node * createLL(struct node arr[] , int size){

	struct node* start=NULL , *pusher;
	int i;
	for(i=0; i<size; i++){

		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->rollno = arr[i].rollno;
		strcpy(temp->name , arr[i].name);
		temp->next = NULL;
		if(start == NULL){
			start = pusher = temp;

		}
		else{
			pusher->next = temp;
			pusher = temp;

		}
	}

	return start;
}


void display(struct node * start){
	struct node* t = start;
	while(t){
		printf("(%d , %s) --> ",t->rollno,t->name);
		t = t->next;
	}
	printf("Null\n");
}

struct node* deleteByRollNumber(struct node* start , int roll){


	struct node* p , *q;

	p = start;
	if(p->rollno == roll){
		start = p->next;
		free(p);
		return start;
	}

	while(p->rollno != roll){
		q = p;
		p = p->next;
	}

	q->next = p->next;
	return start;

}

struct node* reverseLL(struct node* start){

	struct node *p,*q = NULL,*r = NULL;

	p  = start;

	while(p){
		r = q;
		q = p;
		p = p->next;
		q->next = r;

	}
	start = q;
	return start;
}

struct node* insertAtIndex(struct node* start , int index , int rollno , char name[]){


	struct node* p=start;
	if(index == 0){
		struct node* t = (struct node*)malloc(sizeof(struct node));
		t->rollno = rollno;
		strcpy(t->name , name);
		t->next = p;
		start = t;
		return start;
	}

	while(index>1){
		p = p->next;
		index--;
	}
	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->rollno = rollno;
	strcpy(t->name , name);
	t->next = p->next;
	p->next = t;


	return start;
}



int main(){
           int index = 4;
	struct node inputarr[]= {
			{1 , "scott", NULL},
			{2 , "klaus", NULL},
			{3 , "damon", NULL},
			{4 , "oliver", NULL},
			{5 , "rebekah", NULL}
	};


	struct node* start = createLL(inputarr , 5);
	printf("Linkedlist initially:\n");
	display(start);
	printf("\n");


	printf("Linkedlist after insering (55 ,varun) at index %d :\n",index);
	start = insertAtIndex(start , index , 55 , "varun");
	display(start);
	printf("\n");

	printf("Linkedlist after deleting rollno 4 :\n");
	start = deleteByRollNumber(start , 4);
	display(start);
	printf("\n");


	printf("Linkedlist after reversal :\n");
	start = reverseLL(start);
	display(start);



	return 0;
}
