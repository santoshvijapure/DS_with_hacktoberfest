#include<stdio.h>
void bubble(int a[20], int n)
{
    int i, j, k;
    for(i=0; i<n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
            }
        }
    }
}
void display(int a[20], int n)
{
    int i;
    printf("\nSorted Array = ");
    for (i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}
int main()
{
    int a[20], i, n;
    printf("\nEnter Size Of Array = ");
    scanf("%d", &n);
    printf("\nEnter Array Elements = ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubble(a,n);
    display(a,n);
}
