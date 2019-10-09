#Add C++ Program Here

Adding Count Sort program (in C++) here :


// count sort
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int arr[] = {2,9,9,8,1,7,1,3,2,6,6,5,4,1,1,5,2,7,8,1};

    int n = sizeof(arr)/ sizeof(int);
    

    // making the freq array
    vector<int> fm(n,0);

    for(int i=0; i<n; i++){
        fm[arr[i]]++;
    }

    // making prefix sum array using fm
    for(int i=1; i<fm.size(); i++)
    {
        fm[i] += fm[i-1];
    }

    // making the output array using the psa 
    int out[n];
    for(int i=n-1; i>=0; i--)
    {
      out[fm[arr[i]] - 1] = arr[i];
      fm[arr[i]]--;
    }

    for(int i=0; i<n;i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<endl;
    return 0;
}