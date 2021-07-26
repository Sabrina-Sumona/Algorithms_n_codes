#include<stdio.h>

void SelectionSort(int a[], int n)
{
    int i,j,k,temp;
    for(i=0;i<n;i++)
    {
        j = i;
        for(k=i+1;k<n;k++)
        {
            if(a[k]>a[j])
            {
                j = k;
            }
        }

        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main()
{
    int n,i;
    printf("How many numbers?\n");
    scanf("%d",&n);
    int a[n];
    printf("Now enter the numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    SelectionSort(a,n);
    printf("Descending order:  ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}



