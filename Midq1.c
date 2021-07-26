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

int main ()
{
    printf("How many elements?\n");
    scanf("%d",&n);
    int i,a[n];
    printf("Now enter the elements:\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("So, the unsorted numbers are:\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",a[i]);
    }
    int l,h;
    l=0;
    h=n-1;
    quickSort(a,l,h);
    printf("\nAfter quick sorting the element in ascending order:\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",a[i]);
    }

}
