#include <iostream>
using namespace std;

int part(int vector[], int start, int end){

	int pivot = vector[end];
	int P = start;
	int i, aux;

	for(i = start; i<end; i++){
		if(vector[i] <= pivot){	
			swap(vector[i], vector[P]); 
			P++; 

		}
	}

	swap(vector[end], vector[P]);  
	return P;
}

 void Quicksort(int vector[],int start,int end){

    if(start<end)
    {
         int P = part(vector,start,end);
             Quicksort(vector,start,P-1);
             Quicksort(vector,P+1,end);
             printf("\n");
    }
}



int recbinSearch(int v[], int start, int end, int key){ 

	Quicksort(v, start, end);

	int mid = (start+end)/2;

	if(start > end){	
		return -1; 
	}

	if(v[mid] > key){	

		return recbinSearch(v, start, mid-1, key);
		

	}else if(v[mid] < key){	

		return recbinSearch(v, mid+1, end, key); 

	}else{	

		return mid;
	}
}

int main(){
int key;
cout << "Insert the number you want to find: \n";
cin >> key;
int vector[10] = {29, 3, 6, 7, 1, 9, 8, 5, 10, 11};

if(recbinSearch(vector, 0, 9, key) != -1){
cout << key << " is in the position " << recbinSearch(vector, 0, 9, key) << endl;
}else{
cout << key << " is not in the vector." << endl;
}

}