#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int BinarySearch(int a[], int tam, int k){
int l = 0;
int r = tam-1;
    while(l<=r){
        int m = (l+r)/2;
        if(k==a[m]) return m;
        else if(k<a[m]) r = (m-1);
        else l = m+1;
    }
return -1;
}
int main(){
    
   
    return 0;
}
