#include<stdio.h>

int n;

int linearSearch(int a[], int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    printf("How many numbers?\n");
    scanf("%d",&n);
    int a[n],i,x,index;
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Now, enter the number which you want to search:\n");
    scanf("%d",&x);
    index=linearSearch(a,x);
    if(index==-1)
    {
        printf("%d is not found.",x);

    }
    else
    {
        printf("%d is found at index %d\n",x,index);
    }
    return 0;
}
