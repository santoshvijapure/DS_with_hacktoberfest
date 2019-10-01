// LANGUAGE: c
// ENV: gcc
// AUTHOR: Nitin Sultania
// GITHUB: https://github.com/nitinsultania

#include<stdio.h>
#include<stdlib.h>

int *sum(int *A,int *B,int m,int n)
{
    int *C;
    if(m>n)
    {
        C=(int *)malloc((m+1)*sizeof(int));
        for(int i=0;i<=m;i++)
        {
            C[i]=A[i];
        }
        for(int i=0;i<=n;i++)
        {
            C[i]+=B[i];
        }
    }
    else
    {
        C=(int *)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)
        {
            C[i]=B[i];
        }
        for(int i=0;i<=m;i++)
        {
            C[i]+=A[i];
        }
    }
    return C;
}

int *multiply(int *A,int *B,int m,int n)
{
    int *C;
    C=(int *)malloc((m+n+1)*sizeof(int));
    for(int i=0;i<=m+n+1;i++)
    {
        C[i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            C[i+j]+=(A[i]*B[j]);
        }
    }
    return C;
}

int main()
{
    int m,n,k,coff,exp;
    printf("Enter the max power in poly 1: ");
    scanf("%d",&m);
    printf("Enter the max power in poly 2: ");
    scanf("%d",&n);

    int *A=(int *)malloc((m+1)*sizeof(int));
    for(int i=0;i<=m;i++)
    {
        A[i]=0;
    }
    printf("Enter number of terms in poly 1: ");
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        printf("Enter the coff and power");
        scanf("%d%d",&coff,&exp);
        A[exp]=coff;
    }

    int *B=(int *)malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++)
    {
        B[i]=0;
    }
    printf("Enter number of terms in poly 2: ");
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        printf("Enter the coff and power");
        scanf("%d%d",&coff,&exp);
        B[exp]=coff;
    }

    int *C=sum(A,B,m,n);
    int size=(m>n?m:n);
    for(int i=0;i<=size;i++)
    {
        if(C[i]==0)
            continue;
        printf("%d^%d ",C[i],i);
    }

    int *D=multiply(A,B,m,n);
    for(int i=0;i<=m+n+1;i++)
    {
        if(D[i]==0)
            continue;
        printf("%d^%d ",D[i],i);
    }

    return 0;
}