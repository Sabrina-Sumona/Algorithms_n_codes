#include<stdio.h>

#define size 20

int q[size];
int front=-1;
int rear=-1;
int g[size][size];
int vis[size];

void enqueue(int item)
{
    if(rear==(size-1))
    {
        printf("Queue is full!!\n");
    }

    else
    {
        if(rear==-1)
        {
            q[++rear]=item;
            front++;
        }
        else
        {
            q[++rear]=item;
        }
    }
}

int dequeue()
{
    if((front>rear)||(front==-1))
        return 0;
    else
    {
        return q[front++];
    }
}

void BFS(int s,int n)
{
    int p,i;
    enqueue(s);
    vis[s]=1;
    p=dequeue();
    if(p!=0)
    {
        printf("%d ",p);
    }
    while(p!=0)
    {
        for(i=1; i<=n; i++)
        {
            if((g[p][i]!=0)&&(vis[i]==0))
            {
                enqueue(i);
                vis[i]=1;
            }
        }
        p=dequeue();
        if(p!=0)
        {
            printf("%d ",p);
        }
    }
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            BFS(i,n);
        }
    }
}

int main()
{
    int i,j,s,n;
    printf("How many nodes?\n");
    scanf("%d",&n);
    printf("\nNow according to the nodes enter 1 if the nodes are connected else enter 0:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           scanf("%d",&g[i][j]);
        }
    }
    printf("\nHere the Adjacency matrix:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf(" %d",g[i][j]);
        }
        printf("\n");
    }

    vis[i]=0;
    printf("\nNow enter the starting node:\n");
    scanf("%d",&s);
    printf("\nSo, BFS:\n");
    BFS(s,n);
    return 0;
}
