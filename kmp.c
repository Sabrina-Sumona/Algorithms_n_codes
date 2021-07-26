// C++ program for implementation of KMP pattern searching
// algorithm
#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch( char* txt, char* pat)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    int k = 0; // index for pat[]

    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            k++;
            printf("\nMatch: %d\tshift: %d \n",k,i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    printf("\nTotal Matches: %d\n",k);
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver program to test above function
int main()
{
    char T1[1000],P1[100],T2[1000],P2[100];
    printf("Please enter the first searching pattern:\n");
    gets(P1);
    FILE *input1;
    char *filename1 = "text.txt";
    input1 = fopen(filename1,"r");
    fgets(T1,1000,input1);
    KMPSearch(T1,P1);
    fclose(input1);
    printf("Please enter the second searching pattern:\n");
    gets(P2);
    FILE *input2;
    char *filename2 = "test.txt";
    input2 = fopen(filename2,"r");
    fgets(T2,1000,input2);
    KMPSearch(T2,P2);
    fclose(input2);
    return 0;
}
