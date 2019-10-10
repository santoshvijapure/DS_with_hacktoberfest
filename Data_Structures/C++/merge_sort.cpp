// merge sort
# include <iostream>
using namespace std;

void merge(int A[], int low, int q, int high) { 
    int i, j, k; 
    int n1 = q - low + 1; 
    int n2 =  high - q; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = A[low + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = A[q + 1+ j]; 
    i = 0; 
    j = 0; 
    k = low; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            A[k++] = L[i++]; 
        } 
        else
        { 
            A[k++] = R[j++]; 
        } 
    } 
    while (i < n1) 
    { 
        A[k++] = L[i++]; 
    } 
    while (j < n2) 
    { 
        A[k++] = R[j++];  
    } 
}

void mergeSort(int A[], int low, int high) 
{ 
  if (low < high) 
  { 
      int q = low+(high-low)/2; 
      mergeSort(A, low, q); 
      mergeSort(A, q+1, high); 
      merge(A, low, q, high); 
      } 
  
}  

int main()  
{  
    int A[] ={67, 23, 65, 10, 9,-12, 0};
    int n = sizeof(A) / sizeof(A[0]);
    mergeSort(A,0, n);  
    cout<<"Sorted Array in increasing order is : \n"; 
    int i;  
    for (i = 0; i < n; i++)  
        cout << A[i] << " ";  
    cout << endl; 
    return 0;  
}  
