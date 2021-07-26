#include<stdio.h>

int n;

void linearSearch(int a[], int x)
{
    int i,c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            printf("%d is found at index %d\n",x,i);
            c++;
        }
    }
    if(c==0)
    {
        printf("%d is not found.",x);
    }
}

int main()
{
    printf("How many numbers?\n");
    scanf("%d",&n);
    int a[n],i,x;
    printf("Enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Now, enter the number which you want to search:\n");
    scanf("%d",&x);
    linearSearch(a,x);
    return 0;
}
