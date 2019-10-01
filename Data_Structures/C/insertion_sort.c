#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements:  ");
    scanf("%d", &n);
    printf("Enter %d elements:  ", n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=1;i<n;i++)
    {
        int s = i;
        for(int j=i-1;j>=0;j--)
        {
            if (arr[i]<arr[j])
            {
                // swap i and j
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i = j;
            }
            else
            {
                break;
            }
        }
        i = s;
    }
    printf("Sorted array is:  ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
