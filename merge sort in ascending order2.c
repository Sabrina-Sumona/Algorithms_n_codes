#include<stdio.h>

int n;

void mergeSort(int a[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,(q+1),r);
        merge(a,p,q,r);
    }
}

void merge(int a[], int p, int q, int r)
{
    int i,j,k,n1,n2;
    n1=q+1-p;
    n2=r-q;

    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    {
        L[i]=a[p+i];
    }

    for(j=0;j<n2;j++)
    {
        R[j]=a[q+1+j];
    }

    i=0;
    j=0;
    k=p;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++]=R[j++];
        }
    }
    while(i<n1)
    {
        a[k++]=L[i++];
    }

    while(j<n2)
    {
       a[k++]=R[j++];
    }
}

int main()
{
    int i,j;
    printf("How many numbers?\n");
    scanf("%d",&n);
    int a[n];
    printf("Now enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nSo, the numbers are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    int low=0,high;
    high=n-1;
    mergeSort(a,low,high);
    printf("\nAnd after sorting in ascending order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
