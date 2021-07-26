#include<stdio.h>

int main ()
{
    int r1,r2,c1,c2;
    printf ("Please enter the number of rows of 1st matrix:\n");
    scanf("%d",&r1);
    printf ("Please enter the number of columns of 1st matrix:\n");
    scanf("%d",&c1);

    printf ("Please enter the number of rows of 2nd matrix:\n");
    scanf("%d",&r2);
    printf ("Please enter the number of columns of 2nd matrix:\n");
    scanf("%d",&c2);

    int a[r1][c1],b[r2][c2],i,j,k;
    printf ("Please enter the elements of 1st matrix:\n");

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {

            scanf("%d",&a[i][j]);

        }
    }

    printf ("Please enter the elements of 2nd matrix:\n");

    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {

            scanf("%d",&b[i][j]);

        }
    }

    printf ("The 1st matrix is:\n");

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {

            printf("%d  ",a[i][j]);

        }
        printf ("\n");
    }

    printf ("The 2nd matrix is:\n");

    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {

            printf("%d  ",b[i][j]);

        }
        printf ("\n");
    }

    if(c1==r2)
    {
        int c[r1][c2];
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {

                c[i][j]=0;
                for(k=0;k<c1;k++)
                {

                    c[i][j]=c[i][j]+a[i][k]*b[k][j];

                }

            }
        }

        printf ("So, the multiplication of the two matrix is:\n");

        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
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


