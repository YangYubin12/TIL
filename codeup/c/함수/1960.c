#include<stdio.h>
int n, memo[30000]={1,2,4};
int f(int k)
{
    if(memo[k]) return memo[k];
    return memo[k] = (f(k-1) + k) % 137;
}
int main()
{
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
