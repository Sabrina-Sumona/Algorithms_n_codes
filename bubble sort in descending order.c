#include<stdio.h>

void BubbleSort(int a[], int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=(i+1);j<n;j++)
        {
           if(a[j]>a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main()
{
    int n,i,j,temp;
    printf("How many numbers?\n");
    scanf("%d",&n);
    int a[n];
    printf("Now enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    BubbleSort(a,n);

    printf("\nSo, after sorting in descending order we get:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

