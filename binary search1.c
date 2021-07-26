#include<stdio.h>

int n;

int binarySearch(int a[], int x)
{
    int low=0,mid,high=(n-1);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<a[mid])
        {
            high=mid-1;
        }
        else if(x>a[mid])
        {
            low=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    printf("How many numbers?\n");
    scanf("%d",&n);
    int i,x,a[n],index;
    printf("Enter the numbers sequentially:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Now, enter the number which you want to search:\n");
    scanf("%d",&x);
    index=binarySearch(a,x);
    if(index==-1)
    {
        printf("%d is not found.",x);

    }
    else
    {
        printf("%d is found at index %d\n",x,index);
    }
}

