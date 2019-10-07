#include<stdio.h>
#include<stdlib.h>
char arr[20];
int top = -1;
int flag;
void push(char ele){
	if(top == 19)
		printf("The stack is full \n");
	else
		arr[++top] = ele;
}
char pop(){
	char x;
	if(top == -1){
		printf("The stack is empty \n");
		flag++;
	}
	else{
		x = arr[top];
		top--;
	}
	return x;
}
int main(){
	char expression[20];
	printf("Enter the expression to check \n");
	scanf("%s", expression);
	for(int i =0; expression[i] != '\0'; i++){
		char x= expression[i];
		char z;
		if(x == '(' || x == '[' || x == '{')
			push(x);
		if(x == ')'){
			z = pop();
			if(z == '[' || z == '{')
				break;
		}
		if(x == '}'){
			z = pop();
			if(z == '[' || z == '(')
				break;
		}
		if(x == ']'){
			z = pop();
			if(z == '(' || z == '{')
				break;
		}
	}
	if(flag == 0){
		printf("Equal \n");
	}
	else{
		printf("Not equal \n");
	}
	return 0;
}