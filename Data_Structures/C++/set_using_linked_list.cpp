/*
 *  Created on: Oct 6, 2019
 *  Author: Rohit Suthar (iamrohitsuthae)
 */
#include<iostream>
#include<cstdlib>
using namespace std;
class Node {
	int data;
	Node* next;
public:
	Node() {
		data=0;
		next=NULL;
	}
	Node(int data) {
		this->data=data;
		next=NULL;
	}
	bool hasNext() {
		if(this->next != NULL)
			return true;
		return false;
	}
	Node* Next() {
		return this->next;
	}
	friend class set;
};
class set {
	Node* head;
	public:
	set() {
		head=NULL;
	}

	Node* getHead() {
		return head;
	}

	void add(int data) {
		Node* node=new Node(data);
		if(head==NULL){
			head=node;
		}
		else if(head->data == data)
			return;
		else {
			Node* temp=head;
			while(temp->next != NULL && temp->next->data != data) {
				temp=temp->next;
			}
			if(temp->next == NULL)
				temp->next=node;
		}
	}

	void display(Node* node) {
		while(node!= NULL) {
			cout<<node->data<<" ";
			node=node->next;
		}
		cout<<"\n";
	}

	Node* getBefore(int ele) {
		Node* temp1=head;
		while(temp1->next != NULL) {
			if(temp1->next->data == ele)
				break;
			temp1=temp1->next;
		}
		return temp1;
	}

	void remove(int ele) {
		Node* temp=head;
		bool isDel=false;
		if(temp->data == ele) {
		//found
			head=temp->next;
			isDel=true;
			free(temp);
		}
		else {
			while(temp != NULL) {
				if(temp->data  == ele) {
					Node* before = getBefore(ele);
					before->next = temp->next;
					isDel=true;
					delete(temp);
					break;
				}
				temp=temp->next;
			}
		}
		if(isDel) {
			cout<<"Element Deleted"<<endl;
		}
	}

	bool contains(int ele) {
		Node* temp=head;
		while(temp != NULL) {
			if(temp->data == ele)
				return true;
			temp=temp->next;
		}
		return false;
	}

	int size(Node* node) {
		int count=0;
		while(node != NULL) {
			count++;
			node=node->next;
		}
		return count;
	}

	set static Difference(set a,set b) {
		Node* node=a.getHead();;
		set result;
		//A-B
		while(node != NULL) {
			if(!b.contains(node->data))
				result.add(node->data);
			node=node->next;
		}
		return result;
	}

	set static Union(set a,set b) {
		Node* first=a.getHead();
		Node* second=b.getHead();
		set result;
		while(first != NULL) {
				result.add(first->data);
			first=first->next;
		}
		while(second != NULL) {
				result.add(second->data);
			second=second->next;
		}
		return result;
	}

	set static Intersection(set a,set b) {
		Node* node;
		set result;
		node=b.getHead();
		while(node != NULL) {
			if(a.contains(node->data)) {
				result.add(node->data);
			}
			node=node->next;
		}
		return result;
	}

	bool subset(set b) {
		bool isSubset=true;
		Node* node;
		node=b.getHead();
		while(node != NULL) {
			if(!contains(node->data)) {
				isSubset=false;
				break;
			}
			node=node->next;
		}
		return isSubset;
	}
};
int  main() {
	set s,s1,res;
	int choice,ele,n;
	char ch;
	bool check;
	do {
		cout<<"*********ADT SET**********"<<endl;
		cout<<"1. Insert element \n";
		cout<<"2. Remove element \n";
		cout<<"3. Search element \n";
		cout<<"4. Size \n";
		cout<<"5. Subset \n";
		cout<<"6. Intersection \n";
		cout<<"7. Union \n";
		cout<<"8. Difference \n";
		cout<<"9. Display \n";
		cout<<"Enter your choice: ";
		cin>>choice;

		switch(choice) {
		case 1:	cout<<"Enter element: ";
				cin>>ele;
				s.add(ele);
				break;
		case 2:	cout<<"Enter element: ";
				cin>>ele;
				s.remove(ele);
				break;
		case 3:	cout<<"Enter element: ";
				cin>>ele;
				check = s.contains(ele);
				if(check)
					cout<<"Element present"<<endl;
				else
					cout<<"Element not present"<<endl;
				break;
		case 4:	cout<<"Size is: "<<s.size(s.getHead())<<endl;
				break;
		case 5:	cout<<"How many number of elements in set1?: ";
				cin>>n;
				for(int i=0;i<n;i++) {
					cout<<"Enter element: ";
					cin>>ele;
					s.add(ele);
				}
				cout<<"How many number of elements in set2?: ";
				cin>>n;
				for(int i=0;i<n;i++) {
					cout<<"Enter element: ";
					cin>>ele;
					s1.add(ele);
				}
				if(s.subset(s1))
					cout<<"Subset"<<endl;
				else
					cout<<"Not a subset"<<endl;
				s=set::Intersection(res,s);
				s1=set::Intersection(res,s1);
				break;
		case 6:	cout<<"How many number of elements in set1?: ";
				cin>>n;
				for(int i=0;i<n;i++) {
					cout<<"Enter element: ";
					cin>>ele;
					s.add(ele);
				}
				cout<<"How many number of elements in set2?: ";
				cin>>n;
				for(int i=0;i<n;i++) {
					cout<<"Enter element: ";
					cin>>ele;
					s1.add(ele);
				}
				res=set::Intersection(s,s1);
				res.display(res.getHead());
				break;
		case 7:	cout<<"How many number of elements in set1?: ";
				cin>>n;
				for(int i=0;i<n;i++) {
					cout<<"Enter element: ";
					cin>>ele;
					s.add(ele);
				}
				cout<<"How many number of elements in set2?: ";
					cin>>n;
					for(int i=0;i<n;i++) {
						cout<<"Enter element: ";
						cin>>ele;
						s1.add(ele);
					}
				res=set::Union(s,s1);
				cout<<"Union complete"<<endl;
				res.display(res.getHead());
				break;
		case 8:	cout<<"How many number of elements in set1?: ";
				cin>>n;
				for(int i=0;i<n;i++) {
					cout<<"Enter element: ";
					cin>>ele;
					s.add(ele);
				}
				cout<<"How many number of elements in set2?: ";
				cin>>n;
				for(int i=0;i<n;i++) {
					cout<<"Enter element: ";
					cin>>ele;
					s1.add(ele);
				}
				res=set::Difference(s,s1);
				res.display(res.getHead());
				break;
		case 9:	s.display(s.getHead());
				break;
		default:cout<<"Invalid input"<<endl;
				break;
		}
		cout<<"Do you want to continue (Y/N): ";
		cin>>ch;
	}while(ch == 'Y' || ch=='y');

}
