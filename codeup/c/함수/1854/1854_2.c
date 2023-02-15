#include<stdio.h>
long long int n;
int f(long long int n)
{
    if(n==0) return 0;
    return (n%10) + f(n/10);
}
int main()
{
    scanf("%lld", &n);
    printf("%d\n", f(n));
    return 0;
}