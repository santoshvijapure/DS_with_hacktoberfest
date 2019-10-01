// LANGUAGE: c
// ENV: gcc
// AUTHOR: Nitin Sultania
// GITHUB: https://github.com/nitinsultania

#include<stdio.h>
#include<stdlib.h>

int **sum(int **A,int **B,int m,int n,int *k)
{
    int **C;
    C=(int **)malloc((m+n)*sizeof(int *));
    for(int i=0;i<m+n;i++)
    {
        C[i]=(int *)malloc(2*sizeof(int));
    }
    *k=0;
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(A[i][0]<B[j][0])
        {
            C[*k][0]=A[i][0];
            C[*k][1]=A[i][1];
            (*k)++;i++;
        }
        else if(A[i][0]>B[j][0])
        {
            C[*k][0]=B[j][0];
            C[*k][1]=B[j][1];
            (*k)++;j++;
        }
        else
        {
            C[*k][0]=A[i][0];
            C[*k][1]=A[i][1]+B[j][1];
            (*k)++;i++,j++;
        }
        
    }
    if(i<m)
    {
        while(i<m)
        {
            C[*k][0]=A[i][0];
            C[*k][1]=A[i][1];
            (*k)++;i++;
        }
    }
    if(j<n)
    {
        while(j<n)
        {
            C[*k][0]=B[j][0];
            C[*k][1]=B[j][1];
            (*k)++;j++;
        }
    }
    C=(int **)realloc(C,2*(*k)*sizeof(int));
    return C;
}



int main()
{
    int m,n,k,coff,exp;
    printf("Enter the number of elements in poly 1: ");
    scanf("%d",&m);
    printf("Enter the number of elements in poly 2: ");
    scanf("%d",&n);

    int **A=(int **)malloc((m)*sizeof(int *));

    for(int i=0;i<m;i++)
    {
        A[i]=(int *)malloc(2*sizeof(int));
    }

    int **B=(int **)malloc((n)*sizeof(int *));

    for(int i=0;i<n;i++)
    {
        B[i]=(int *)malloc(2*sizeof(int));
    }

    printf("Enter the terms in poly 1 (power and coeff): \n");
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&exp,&coff);
        A[i][0]=exp;
        A[i][1]=coff;
    }

    printf("Enter the terms in poly 2 (power and coeff): \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&exp,&coff);
        B[i][0]=exp;
        B[i][1]=coff;
    }


    int **C=sum(A,B,m,n,&k);
    for(int i=0;i<k;i++)
    {
        printf("%d^%d ",C[i][1],C[i][0]);
    }

    return 0;
}