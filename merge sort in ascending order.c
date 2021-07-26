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
    n1=(q-p)+1;
    n2=r-q;

    int L[n1+1],R[n2+1];

    for(i=0;i<n1;i++)
    {
        L[i]=a[p+i];
    }

    for(j=0;j<n2;j++)
    {
        R[j]=a[q+j+1];
    }

    L[n1+2]=123456789;
    R[n2+2]=123456789;

    i=0;
    j=0;

    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k] = L[i];
            i=i+1;
        }
        else
        {
            a[k]=R[j];
            j=j+1;
        }
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
