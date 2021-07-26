#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Naive(char T[], char P[])
{
    int n = strlen(T);
    int m = strlen(P);
    int s,i=0,j;


    for (s = 0; s <= (n-m); s++)
    {
        for (j = 0; j < m; j++)
        {
            if (T[s + j] != P[j])
            {
                break;
            }

        }

        if (j == m)
        {
            i++;
            printf("\nMatch: %d\tshift: %d \n",i,s);
        }


    }
    printf("\nTotal Matches: %d\n",i);
}

int main()
{
    char T1[1000],P1[100],T2[1000],P2[100];
    printf("Please enter the first searching pattern:\n");
    gets(P1);
    FILE *input1;
    char *filename1 = "text.txt";
    input1 = fopen(filename1,"r");
    fgets(T1,1000,input1);
    Naive(T1,P1);
    fclose(input1);
    printf("Please enter the second searching pattern:\n");
    gets(P2);
    FILE *input2;
    char *filename2 = "test.txt";
    input2 = fopen(filename2,"r");
    fgets(T2,1000,input2);
    Naive(T2,P2);
    fclose(input2);
    return 0;
}
