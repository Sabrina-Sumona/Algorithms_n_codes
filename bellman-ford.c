#include<stdio.h>
#include<conio.h>

#define infinity 999

#define vertices 20

#define edges 20

int cost[vertices][edges];
int d[vertices];
int vis[vertices];

void Dij(int n,int m,int s)
{
    int i,u,count,w,min;
    for(i=1; i<=n; i++)
    {
        vis[i]=0;
        d[i]=cost[s][i];
    }

    count=2;
    while(count<=n)
    {
        min=99;
        for(w=1; w<=n; w++)
        {
            if(d[w]<min && !vis[w])
            {
                min=d[w];
                u=w;
            }
        }

        vis[u]=1;
        count++;
        for(w=1; w<=m; w++)
        {
            if((d[u]+cost[u][w]<d[w]) && !vis[w])
            {
                d[w]=d[u]+cost[u][w];
            }
        }
    }
}

int main()
{
    int i,j,s,n,m;
    printf("How many vertices?\n");
    scanf("%d",&n);
    printf("How many edges?\n");
    scanf("%d",&m);
    printf("\nNow enter the costs:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
           scanf("%d",&cost[i][j]);
           if(cost[i][j]==0)
           {
               cost[i][j]=infinity;
           }
        }
    }
    printf("\nHere the cost matrix:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf(" %d",cost[i][j]);
        }
        printf("\n");
    }

    printf("\nNow enter the starting node:\n");
    scanf("%d",&s);
    printf("\nSo, the shortest path:\n");
    Dij(n,m,s);
    for(i=1; i<=n; i++)
    {
         if(i!=s)
            printf("%d->%d, cost=%d\n",s,i,d[i]);
    }
    return 0;
}

