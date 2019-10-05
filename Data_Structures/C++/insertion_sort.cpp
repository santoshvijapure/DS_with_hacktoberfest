
#include <iostream>
using namespace std;

void insertionSort(int A[], int low, int high)
{
    int key;
    for (int i=low+1;i<=high;i++)
    {
        key=A[i];
        int j=i-1;
        while (j>=low && A[j]>key)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=key;
    }
    cout<<"Sorted Array in increasing order is : \n"; 
    int i;  
    for (i = 0; i < high; i++)  
        cout << A[i] << " ";  
    cout << endl;
}
 
int main()  
{  
    int A[] ={67, 23, 65, 10, 9,-12, 0};
    int n = sizeof(A) / sizeof(A[0]);
    insertionSort(A,0, n);   
    return 0;  
}  
