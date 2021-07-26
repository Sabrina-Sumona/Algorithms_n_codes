#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define d 256

void Rabin_Karp(char T[], char P[], int q)
{
    int m = strlen(P);
    int n = strlen(T);
    int i, j,k=0;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }


    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (T[i + j] != P[j])
                    break;
            }

            if (j == m)
            {
                k++;
                printf("\nMatch: %d\tshift: %d \n",k,i);
            }
        }

        if (i < n - m)
        {
            t = (d * (t - T[i] * h) + T[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
    printf("\nTotal Matches: %d\n",k);
}

int main()
{
    char T1[1000],P1[100],T2[1000],P2[100];
    int q=13;
    printf("Please enter the first searching pattern:\n");
    gets(P1);
    FILE *input1;
    char *filename1 = "text.txt";
    input1 = fopen(filename1,"r");
    fgets(T1,1000,input1);
    Rabin_Karp(T1,P1,q);
    fclose(input1);
    printf("Please enter the second searching pattern:\n");
    gets(P2);
    FILE *input2;
    char *filename2 = "test.txt";
    input2 = fopen(filename2,"r");
    fgets(T2,1000,input2);
    Rabin_Karp(T2,P2,q);
    fclose(input2);
    return 0;
}
