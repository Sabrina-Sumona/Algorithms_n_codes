#include<stdio.h>

int n;

void quickSort(int a[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=Partiton(a,p,r);
        quickSort(a,p,(q-1));
        quickSort(a,(q+1),r);
    }
}

int Partiton(int a[],int p, int r)
{
    int x,i,j,temp;
    x=a[r];
    i=(p-1);
    for(j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[j];
    a[j]=temp;
    return (i+1);
}

int main()
{
    int i,j,temp;
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
    int p=0,r;
    r=n-1;
    quickSort(a,p,r);
    printf("\nAnd after sorting in ascending order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
