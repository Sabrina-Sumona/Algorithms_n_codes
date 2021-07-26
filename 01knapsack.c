#include<stdio.h>

int max(int a, int b)
{
    if (a>b)
        return a;
    else
      return b;
}

int knapsack(int M, int w[], int v[],int n)
{
    int i,j;
    int C[n+1][M+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=M;j++)
        {
            if(i==0 || j==0)
                C[i][j]=0;
            else if (w[i-1]>j)
                C[i][j] = C[i-1][j];
            else
                C[i][j] = max(v[i-1]+C[i-1][j-w[i-1]],C[i-1][j]);

        }
    }
    return C[n][M];
}

int main()
{
    int M,w[20],v[20],n,i;
    printf("How many items?\n");
    scanf("%d",&n);
    printf("Enter the weights and values:\n");
    for(i=0;i<n;i++)
    {
       scanf("%d%d",&w[i],&v[i]);
    }
    printf("Enter the maximum weight:\n");
    scanf("%d",&M);
    int val = knapsack(M, w, v, n);
    printf("So the total profit which can be acquired : %d\n",val);
    return 0;
}
