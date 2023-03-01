#include<stdio.h>
int memo[1000011]={1,1,2};
int f(int k)
{
    if (memo[k]) return memo[k];
    else return memo[k] = (f(k-1) + f(k-2) + f(k-3));
}
int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", f(x));
    return 0;
}
