#include <stdio.h>
#define MAX 20

void knapsackDP(int,int);
int max(int,int);
void backtracking();
int weight[MAX],value[MAX],W,no,*x;
int v[MAX][MAX];


void main()
{
 int i,j;
 printf("\n Enter number of Object you want:");
 scanf("%d",&no);
 printf("\n Enter weight and values in ascending order of vales");;
 for(i=1;i<=no;i++)
 {
  printf("\n Enter Weight and Value for Object %d:",i);
  scanf("%d %d",&weight[i],&value[i]);
 }
 printf("\n Enter knapsack Capacity:");
 scanf("%d",&W);

 knapsackDP(no,W);
 backtracking();

}

void knapsackDP(int no,int W)
{
 int i,j;

 for(i=0;i<= W ;i++)
  v[0][i]=0;

 for(i=0;i<= no;i++)
  v[i][0]=0;

 for(i=1;i<= no;i++)
 {
  for(j=1;j<= W;j++)
  {
   if((j-weight[i])< 0)
    v[i][j]=v[i-1][j];
   else
    v[i][j]=max(v[i-1][j],v[i-1][j-weight[i]]+value[i]);
  }
 }
 printf("\n \t      ");
 for(i=0;i<= W;i++)
  printf("%2d  ",i);

 printf("\n-----------------------------------------------------------------------------");

 for(i=0;i<=no;i++)
 {
  printf("\n w%d=%2d v%d=%2d |",i,weight[i],i,value[i]);
  for(j=0;j<= W;j++)
   printf("%2d  ",v[i][j]);

 }
 printf("\n-----------------------------------------------------------------------------");
 printf("\n Maximum value carry by knapsack is:%2d",v[no][W]);
 printf("\n-----------------------------------------------------------------------------");
}

int max(int a,int b)
{
 return (a >b)?a:b;
}

void backtracking()
{

 int j1,i;
 j1=W;
 printf("\nIncluded Object \t weight \t value");
 printf("\n-----------------------------------------------------------------------------");
 for(i=no;i >=0;i--)
 {

  if(v[i][j1]!=v[i-1][j1] && (v[i][j1]==v[i-1][j1-weight[i]]+value[i]))
  {
   printf("\n%2d \t\t\t  %2d   \t\t %2d",i,weight[i],value[i]);
   j1=j1-weight[i];
  }

 }


}
