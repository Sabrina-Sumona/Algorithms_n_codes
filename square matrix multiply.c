#include<stdio.h>

int main ()
{
    int m,n;
    printf ("Please enter the number of rows of 1st matrix:\n");
    scanf("%d",&m);
    printf ("Please enter the number of columns of 2nd matrix:\n");
    scanf("%d",&n);

    int a[m][m],b[n][n],c[m][m],i,j,k;
    printf ("Please enter the elements of 1st matrix:\n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {

            scanf("%d",&a[i][j]);

        }
    }

    printf ("Please enter the elements of 2nd matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

            scanf("%d",&b[i][j]);

        }
    }

    printf ("The 1st matrix is:\n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {

            printf("%d  ",a[i][j]);

        }
        printf ("\n");
    }

    printf ("The 2nd matrix is:\n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {

            printf("%d  ",b[i][j]);

        }
        printf ("\n");
    }

    if(m==n)
    {
        int p=m;
        int c[p][p];
        for(i=0;i<p;i++)
        {
            for(j=0;j<p;j++)
            {

                c[i][j]=0;
                for(k=0;k<p;k++)
                {

                    c[i][j]=c[i][j]+a[i][k]*b[k][j];

                }

            }
        }

        printf ("So, the multiplication of the two matrix is:\n");

        for(i=0;i<p;i++)
        {
            for(j=0;j<p;j++)
            {

                printf("%d  ",c[i][j]);

            }
            printf ("\n");
        }
    }
    else
    {
        printf("Multiplication is not possible.");
    }

    return 0;
}
