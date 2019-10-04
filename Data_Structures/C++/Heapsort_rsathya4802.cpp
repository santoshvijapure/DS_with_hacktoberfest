// LANGUAGE: c++
// ENV: gcc
// AUTHOR: Sathyanarayanan R
// GITHUB: https://github.com/rsathya4802
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
void swap(ll a[],ll x,ll y)
{
    ll temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}
void heap_arr(ll a[],ll n,ll pos)
{
    ll lar=pos;
    ll l=2*pos+1,r=2*pos+2;
    if(l<n && a[l]>a[lar])
        lar=l;
    if(r<n && a[r]>a[lar])
        lar=r;
    if(pos!=lar)
    {
        swap(a,lar,pos);
        heap_arr(a,n,lar);
    }
}
void heapsort(ll a[],ll n)
{
    for(ll i=n/2-1;i>=0;i--)
        heap_arr(a,n,i);
    for(ll i=n-1;i>=0;i--)
    {
        swap(a,0,i);
        heap_arr(a,i,0);
    }
}
int main()
{
    int a[100];
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    heapsort(a,n);
    cout<<"After Sorting: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    
}
