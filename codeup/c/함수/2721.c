#include <stdio.h>
int main()
{
    char S1[20];
    char S2[20];
    char S3[20];
    gets(S1);
    gets(S2);
    gets(S3);
    char s1,s2,s3;
    int i,j,k;
    for(i = 0; S1[i] != '\0'; i++){}
    s1 = S1[i-1];
    for(j = 0; S2[j] != '\0'; j++){}
    s2 = S2[j-1];
    for(k = 0; S3[k] != '\0'; k++){}
    s3 = S3[k-1];
    if(s1 == S2[0] && s2 == S3[0] && s3 == S1[0])
        printf("good");
    else
        printf("bad");
    return 0;
}
