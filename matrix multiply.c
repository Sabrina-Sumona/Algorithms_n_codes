#include<stdio.h>
int main()
{
    int A[3][3]= {1,2,3,
                  4,5,6,
                  7,8,9};
    int B[3][3]= {1,5,6,
                  7,8,9,
                  1,2,5};
    int i,j;

    for(i=0; i<3; i++)
    {
        printf("\n");
        for(j=0; j<3; j++)
            printf("%d\t",A[i][j]);
    }
    printf("\n*\n");
    for(i=0; i<3; i++)
    {
        printf("\n");
        for(j=0; j<3; j++)
            printf("%d\t",B[i][j]);
    }

    printf("\nMultiply Of A and B\n");
    matrix_multiply(A,B);
}

void matrix_multiply(int A[3][3],int B[3][3])
{
    int r,i,j,k, C[3][3];
    int A_columns=3;
    int B_row=3;
    if(A_columns!=B_row)
    {
        printf("\nIncompatible Dimensions!\n");
    }
    else
    {
        r=3;
        for(i=0; i<r; i++)
        {
            for(j=0; j<r; j++)
            {
                C[i][j]=0;
                for(k=0; k<r; k++)
                    C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
            }
        }

        for(i=0; i<3; i++)
        {
            printf("\n");
            for(j=0; j<3; j++)
                printf("%d\t",C[i][j]);
        }
    }
}
