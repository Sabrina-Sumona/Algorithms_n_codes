#include<stdio.h>
int main ()
{
    int i,j,l;
    char s1[100],s2[100],s3[100];
    printf("Please enter the two strings:\n");
    scanf("%s%s",s1,s2);

    for(i=0;s1[i]!='\0';i++)
    {
        s3[i]=s1[i];
    }
    l=i;

    for(j=0;s2[j]!='\0';j++)
    {
        s3[l+j]=s2[j];
    }
    s3[l+j]='\0';

    printf("So the new string is %s",s3);

    return 0;

}


