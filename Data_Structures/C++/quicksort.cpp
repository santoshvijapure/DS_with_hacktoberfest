//quick sort
#include<iostream>
using namespace std;
#include<conio.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int f, int l){
	int pivot = a[l];
	int i = f-1;
	
	for(int j=f; j<=l-1; j++){
		if(a[j]<=pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[l]);
	return(i+1);
}

int quicksort(int a[], int f, int l){
	if(f<l){
		int pi;
		pi = partition(a, f, l);
		quicksort(a, f,pi-1);
		quicksort(a, pi+1, l);
		//merge(a, f, mid, mid+1, l);
		}
}

int main(){
	int n, i;
	cout<<"enter n: ";
	cin>>n;
	int a[n];
	cout<<"enter a: ";
	for(i=1; i<=n; i++)
		cin>>a[i];
	quicksort(a, 1, n);	
	for(i=1; i<=n; i++)
		cout<<a[i]<<" ";
		
    return 0;
}
