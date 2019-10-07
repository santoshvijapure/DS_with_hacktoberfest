#include<stdio.h>
#include<stdlib.h>
int arr[20];
int top = -1;
void push(int ele){
	if(top == 19)
		printf("Overflow\n");
	else
		arr[++top] = ele;
}
int peek(){
	return arr[top];
}
void pop(){
	top--;
}
int empty(){
	if(top == -1)
		return 1;
	else
		return 0;
}
int area(int bars[], int n){
	int max = 0;
	int tp;
	int are;
	int i = 0;
	while(i < n){
		if(empty() || bars[peek()] <= bars[i])
			push(i++);
		else{
			tp = peek();
			pop();
			are = bars[tp] * (empty() ? i : i - peek() - 1);
			if(max < are)
				max = are;
		}
	}
	while(!empty()){
		tp = peek();
		pop();
		are = bars[tp] * (empty() ? i : i - peek() - 1);
		if(max < are)
			max = are;
	}
	return max;
}
int main(){
	int bars[7] = {6,2,5,4,5,1,6};
	int area_max = area(bars,7);
	printf("Maximum area is %d \n", area_max);
	return 0;
}