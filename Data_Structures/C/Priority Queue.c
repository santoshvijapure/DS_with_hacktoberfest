#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int n=5;
int pq[2][10];
int index=0;
void enqueue(int k,int pri)
{
	int i;
	if(index<n)						
	{
	 for(i=index-1;i>=0;i--)
	 {
	 	if(pri<=pq[1][i])
	 	{
	 		pq[0][i+1]=k;
	 		pq[1][i+1]=pri;
	 		index++;
	 		break;
		 }
		 else
		 {
		 	pq[0][i+1]=pq[0][i];
		 	pq[1][i+1]=pq[1][i];
		 }
	 }
	 if(i==-1)
	{
		pq[0][0]=k;
		pq[1][0]=pri;
		index++;
	}
	
	}
	else
	{
		printf("The Queue is FULL!!\n");
	}
}
void dequeue()
{
	if(index==0)
	{
		printf("The Queue is EMPTY!!\n");
	}
	else
	{
		int i;
		printf("The element removed is %d and its priority is %d\n",pq[0][0],pq[1][0]);
		for(i=1;i<index;i++)
		{
			pq[0][i-1]=pq[0][i];
		 	pq[1][i-1]=pq[1][i];
		}
		index--;
	}
}
void print()
{
	if(index==0)
	{
		printf("No elements are available!!\n");
	}
	else
	{
		int i;
		printf("The elements and their respective priorities are:\n");
		for(i=0;i<index;i++)
	{
		printf("%d %d\n",pq[0][i],pq[1][i]);
	}
	}
}
void main()
{
	int a,k,pri;
	while(1)
	{
		printf("Select your option:\n");
		printf("1.Enqueue\n2.Dequeue\n3.Print elements\n4.Exit\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: printf("Enter the element to be inserted and its priority:\n");
			        scanf("%d%d",&k,&pri);
			        enqueue(k,pri);
			        break;
			case 2: dequeue();
			        break;
			case 3: print();
			        break;
			case 4: exit(0);
			        break;
		}
	}
	getch();
}
