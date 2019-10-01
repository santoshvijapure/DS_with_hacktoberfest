#include<stdio.h>
#include<stdlib.h>

void display(int **a)
{
    int t=1;
    printf("\n");
    for(int i=0;i<a[0][0];i++)
    {
        for(int j=0;j<a[0][1];j++)
        {
            if((t<=a[0][2])&&(i==a[t][0])&&(j==a[t][1]))
            {
                printf("%d ",a[t][2]);
                t++;
            }
            else
            {
                printf("%d ",0);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int compare(int a,int b)
{
    if(a>b)
        return -1;
    else if(a<b)
        return 1;
    else
        return 0;    
}

int **add(int **a,int **b)
{
    int **c=NULL;
    int n1=a[0][2],n2=b[0][2];
    int i=1,j=1,k=1;
    
    if((a[0][0]!=b[0][0])||(a[0][1]!=b[0][1]))
        return c;
        
    c=(int **)malloc((n1+n2+1)*sizeof(int *));
    for(i=0;i<(n1+n2+1);i++)
    {
        c[i]=(int *)malloc(3*sizeof(int));
    }
    
    c[0][0]=a[0][0];
    c[0][1]=a[0][1];
    i=1,j=1;
    
    int m1,m2;
    while((i<=n1)&&(j<=n2))
    {
        m1=compare(a[i][0],b[j][0]);
        switch(m1)
        {
            case 0:m2=compare(a[i][1],b[j][1]);
                            switch(m2)
                            {
                                case 0:c[k][0]=a[i][0];
                                               c[k][1]=a[i][1];
                                               c[k][2]=a[i][2]+b[j][2];
                                               i++;k++;j++;
                                               break;
                                case 1:c[k][0]=a[i][0];
                                               c[k][1]=a[i][1];
                                               c[k][2]=a[i][2];
                                               i++;k++;
                                               break;
                                case -1:c[k][0]=b[j][0];
                                                 c[k][1]=b[j][1];
                                                 c[k][2]=b[j][2];
                                                 k++;j++;
                                                 break;
                            }
                           break;
            case 1:c[k][0]=a[i][0];
                            c[k][1]=a[i][1];
                            c[k][2]=a[i][2];
                            i++;k++;
                            break;
            case -1:c[k][0]=b[j][0];
                             c[k][1]=b[j][1];
                             c[k][2]=b[j][2];
                             j++;k++;
                             break;
        }
    }
    
    
    if(i<=n1)
    {
        while(i<=n1)
        {
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2];
            k++;i++;
        }
    }
    else
    {
        while(j<=n2)
        {
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            c[k][2]=b[j][2];
            k++;j++;
        }
    }
    c[0][2]=k-1;
    c=realloc(c,k*3*sizeof(int));
    return c;
}

int main()
{
    int r1,c1,n1,r2,c2,n2;
    int **a,**b,**c;
    register int i;
    printf("Enter the Row and Column and no elements in Matrix 1\n");
    scanf("%d%d%d",&r1,&c1,&n1);
    printf("Enter the Row and Column and no elements in Matrix 2\n");
    scanf("%d%d%d",&r2,&c2,&n2);
    
    a=(int **)malloc((n1+1)*sizeof(int *));
    for(i=0;i<(n1+1);i++)
    {
        a[i]=(int *)malloc(3*sizeof(int));
    }
    
    b=(int **)malloc((n2+1)*sizeof(int *));
    for(i=0;i<(n2+1);i++)
    {
        b[i]=(int *)malloc(3*sizeof(int));
    }
    
    a[0][0]=r1;a[0][1]=c1;a[0][2]=n1;
    b[0][0]=r2;b[0][1]=c2;b[0][2]=n2;
    
    printf("\nEnter the row no, column no and the element for matrix 1\n");  
    for(i=1;i<=n1;i++)
    {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    }
    display(a);
    
    printf("\nEnter the row no,column no and the element for matrix 2\n");
    for(i=1;i<=n2;i++)
    {
       scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]); 
    }
    display(b);
    
    c=add(a,b);
    
    if(c==NULL)
        printf("Matrix cant be added");
    else
        display(c);
    return 0;
}
