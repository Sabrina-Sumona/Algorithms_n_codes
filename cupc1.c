#include <stdio.h>
#include <string.h>

char Checkequivalent(char s[])
{
    char a1[100000],a2[100000];
    int l=0,c=0;
    l=strlen(s);
    if (l%2==0)
    {
        return s;
    }
    while (c<(l/2))
    {
      a1[c] = s[c];
      c++;
    }
    c=0;
    while (c<l)
    {
      a2[c] = s[l/2+c];
      c++;
    }
    char b1[]=Checkequivalent(a1);
    char b2[]=Checkequivalent(a2);
    if(b1>b2)
    {
        return (strcat(b2,b1));
    }
    else
    {
        return (strcat(b1,b2));
    }
}
int main()
{
    char a[200000],b[200000];
    scanf("%s",a);
    scanf("%s",b);
    int c=strcmp(Checkequivalent(a),Checkequivalent(b));
    if (c==0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}
