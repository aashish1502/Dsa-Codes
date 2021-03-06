#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void quick_sort(int a[100],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
int partition(int a[100],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
        {
            i++;
        }while(a[i]<v&&i<=u);
        
        do
        {
            j--;
        }while(a[j]>v);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    return(j);
}

void mergesort(int a[100],int i, int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}

void merge(int a[100],int i1,int j1, int i2,int j2)
{
    int temp[100];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;
    
    while(i<=j1&&j<=j2)
    {
        if(a[i]<a[j])
        temp[k++]=a[i++];
        else
        temp[k++]=a[j++];
    }
    
    while(i<=j1)
        temp[k++]=a[i++];
    
    while(j<=j2)
        temp[k++]=a[j++];
    
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}


void main()
{
    int a[100],n,i,op;
    while(1)
    {
        printf("\n1.Quick sort\n2.Merge sort\n\n3.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("QUICK SORT\n");
                printf("Enter no of elements\n");
                scanf("%d",&n);
                printf("Enter the Number\n");
                
                for(i=0;i<=n-1;i++)
                    scanf("%d",&a[i]);
                
                quick_sort(a,0,n-1);
                printf("sorted array is: ");
                
                for(i=0;i<=n-1;i++)
                    printf("\t%d",a[i]);
                printf("\n");
                break;
            case 2:printf("MERGE SORT\n");
                printf("Enter no of elements\n");
                scanf("%d",&n);
                printf("Enter the NUmbers:\n");
                for(i=0;i<=n-1;i++)
                    scanf("%d",&a[i]);
                
                mergesort(a,0,n-1);
                printf("sorted array is: ");
                
                for(i=0;i<=n-1;i++)
                    printf("\t%d",a[i]);
                printf("\n");
                break;

            case 3:exit(1);
            default:printf("Invalid Choice\n");
        }
    }
}
