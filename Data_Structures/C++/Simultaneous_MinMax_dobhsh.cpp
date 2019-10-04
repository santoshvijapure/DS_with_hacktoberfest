// LANGUAGE: C++
// ENV: gcc
// AUTHOR: Shuchita Dobhal
// GITHUB: https://github.com/dobhsh

/* structure is used to return two values from minMax() */
#include<stdio.h>
#include<iostream>
using namespace std;
class numbers 
{
public :
  int min;
  int max;
};  
 
numbers getMinMax(int arr[], int low, int high)
{
  numbers minmax, mml, mmr;       
  int mid;
   
  /* If there is only on element */
  if (low == high)
  {
     minmax.max = arr[low];
     minmax.min = arr[low];     
     return minmax;
  }    
   
  /* If there are two elements */
  if (high == low + 1)
  {  
     if (arr[low] > arr[high])  
     {
        minmax.max = arr[low];
        minmax.min = arr[high];
     }  
     else
     {
        minmax.max = arr[high];
        minmax.min = arr[low];
     }  
     return minmax;
  }
   
  /* If there are more than 2 elements */
  mid = (low + high)/2;  
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid+1, high);  
   
  /* compare minimums of two parts*/
  if (mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;     
 
  /* compare maximums of two parts*/
  if (mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;     
  
  return minmax;
}
 

int main()
{
	int n;
	cout<<"enter number of elements";
	cin>>n;
  int* arr=new int[n];
cout<<"enter the numbers";
for(int i=0;i<n;i++){
	cin>>arr[i];
}

  numbers minmax = getMinMax(arr, 0, n-1);
  cout<<"\n Minimum element is ="<<minmax.min;
  cout<<"\nMaximum element is="<<minmax.max;
  return 0;
}
