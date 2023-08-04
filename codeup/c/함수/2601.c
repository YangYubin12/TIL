#include<stdio.h>
int i, n, DT[44]={0,1,1,};
int main()
{
    scanf("%d", &n);
    for(i=3; i<=n; i++)
        DT[i] = DT[i-1] + DT[i-2];
    printf("%d", DT[n]);
    return 0;
}
