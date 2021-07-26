#include<stdio.h>

#define size 20

int stack[size];
int tos=-1;
int g[size][size];
int vis[size];

void push(int item)
{
    if(tos==(size-1))
    {
        printf("The Stack is full.");
    }
    else
    {
        stack[++tos]=item;
    }
}

int pop()
{
    if(tos==-1)
    {
        return 0;
    }
    else
    {
        return stack[tos--];
    }
}

void DFS(int s,int n)
{
    int p,i;
    push(s);
    vis[s]=1;
    p=pop();
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
                push(i);
                vis[i]=1;
            }
        }
        p=pop();
        if(p!=0)
        {
            printf("%d ",p);
        }
    }
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            DFS(i,n);
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
    printf("\nNow enter the searching node:\n");
    scanf("%d",&s);
    printf("\nSo, DFS:\n");
    DFS(s,n);
    return 0;
}
