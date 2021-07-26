#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int board[20],count;

void Print(int n)
{
   int i,j;
   printf("\nSolution %d:\n\n",++count);
   for(i=1;i<=n;i++)
   {
       printf("\t%d",i);
   }
   for(i=1;i<=n;i++)
   {
       printf("\n\n%d",i);
       for(j=1;j<=n;j++)
       {
           if(board[i]==j)
           {
               printf("\tQ");
           }
           else
           {
               printf("\t-");
           }
       }
   }
}

int Place(int row, int column)
{
    int i;
    for(i=1; i<=row-1;i++)
    {
        if(board[i]==column)
        {
            return 0;
        }
        else
        {
            if(abs(board[i]-column)==abs(i-row))
            {
                return 0;
            }
        }

    }
    return 1;
}

void Queen(int row, int n)
{
    int column;
    for(column=1;column<=n;column++)
    {
        if(Place(row,column))
        {
            board[row]=column;
            if(row==n)

            {
                Print(n);
            }
            else
            {
                Queen(row+1,n);
            }
        }
    }

}

int main()
{
    int n;
    printf("Enter the number of queen:\n");
    scanf("%d",&n);
    Queen(1,n);
    return 0;
}
