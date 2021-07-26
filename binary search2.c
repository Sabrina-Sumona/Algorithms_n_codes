#include<stdio.h>

int n;

int binarySearch(int a[], int x,int low, int high)
{
    int mid;
    if(low==high)
    {
        if(x==a[low])
        {
            return high;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        mid=(low+high)/2;
        if(x==a[mid])
        {
            return mid;
        }
        else if(x<a[mid])
        {
            return binarySearch(a,x,low,(mid-1));
        }
        else
        {
            return binarySearch(a,x,(mid+1),high);
        }
    }
}

int main()
{
    int i,x;
    printf("How many numbers?\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers sequentially:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Now, enter the number which you want to search:\n");
    scanf("%d",&x);
    int index,low=0,high;
    high=n-1;
    index=binarySearch(a,x,low,high);
    if(index==-1)
    {
        printf("%d is not found.\n",x);
    }
    else
    {
        printf("%d is found at index %d.\n",x,index);
    }
}

