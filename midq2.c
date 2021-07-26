#include<stdio.h>

#define size 20

int g[size][size];
int v[size];
int stack[size];
int tos=-1;

void push(int item)
{
    if(tos==(size-1))
        printf("Stack is full!!!");
    else
        stack[++tos]=item;
}

int pop()
{
    if(tos==-1)
        return 0;
    else
        return stack[tos--];
}

void DFS(int s, int n)
{
    int i,j,p;
    push(s);
    v[s]=1;
    p=pop(s);
    if(p!=0)
    {
        printf("%d ",p);
    }
    while(p!=0)
    {
        for(i=1;i<=n;i++)
        {
            if(g[p][i]!=0 && v[i]==0)
            {
                push(i);
                v[i]=1;
            }
        }
        p=pop(i);
        if(p!=0)
        {
            printf("%d ",p);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            DFS(i,n);
        }
    }
}
int main()
{
    int n;
    printf("How many nodes?\n");
    scanf("%d",&n);
    int i,j,s;
    printf("Now according to the nodes enter 1 if nodes are connected else enter 0:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    printf("So, the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    printf("Now enter the starting node:\n");
    scanf("%d",&s);
    v[s]=0;
    printf("So DFS:\n");
    DFS(s,n);
}
