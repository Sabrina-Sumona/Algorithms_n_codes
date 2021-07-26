#include <stdio.h>
#include <string.h>

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
    char T[100],P[100];
    printf("Please enter the text and searching pattern:\n");
    gets(T);
    gets(P);
    Naive(T,P);
    return 0;
}
