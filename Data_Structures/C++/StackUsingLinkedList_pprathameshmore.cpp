// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author : Prathamesh More
//Compiler: Microsoft Visual Studio (Don't confuse with Visual Studio Code)
//Language: C++14

#include <iostream>
#include<array>

struct Node {
	int data;
	Node* next;
} node;

void display(Node* top) {
	
	Node* temp = top;

	if (top == NULL) {
		std::cout << "Stack is empty" << std::endl;
	}
	else {
		while (temp->next != NULL) {
			std::cout << "Stack elements are : " <<  temp->data << std::endl;
			temp = temp->next;
		}
	}
}

void push(Node** top) {
	int data{};

	Node* ptr = new Node;
	
	std::cout << "Enter data : " << std::endl;
	std::cin >> data;
	ptr->data = data;
	ptr->next = *top;
	*top = ptr;
	display(*top);
}

void pop(Node** top) {
	Node* ptr = new Node;
	if (*top == NULL) {
		std::cout << "Stack is underflow " << std::endl;
		return;
	}
	int data = (*top)->data;
	ptr = *top;
	(*top) = ptr->next;
	free(ptr);

	display(*top);

}


int main() {

	int choice{};

	Node* top = NULL;

	do {
		std::cout << "Welcome to Stack" << std::endl;
		std::cout << "1. Push elements " << std::endl;
		std::cout << "2. Pop elemtns " << std::endl;
		std::cout << "3. Show stack elements" << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			push(&top);
			break;
		case 2:
			pop(&top);
			break;

		case 3:
			display(top);
			break;
		}
		
	} while (1);
	

	std::cin.get();

}
