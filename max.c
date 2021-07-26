#include<stdio.h>

int Max(int a[], int n)
{
    int result,i;
    result = a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>result)
            {
                result=a[i];
            }
    }

    return result;
}

int main()
{
    int n,i,result;
    printf("How many numbers?\n");
    scanf("%d",&n);
    int a[n];
    printf("Now enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    result = Max(a,n);
    printf("Maximum number = %d",result);
    return 0;
}
