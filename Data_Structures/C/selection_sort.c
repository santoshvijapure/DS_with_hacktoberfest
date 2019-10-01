#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements:  ");
    scanf("%d",&n);
    printf("Enter %d elements:  ", n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        int small = arr[i], location=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<small)
            {
                small = arr[j];
                location=j;
            }
        }
        int t=arr[i];
        arr[i] = arr[location];
        arr[location] = t;
    }
    printf("Sorted array is:  ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
