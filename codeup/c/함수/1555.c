#include <stdio.h>

int n;

long long int f(int n)
{
    long long int i, s = 0;
    for (i = 1; i <= n; i++)
    {
        s += i;
    }
    return s;
}

int main()
{
  scanf("%d", &n);
  printf("%lld\n", f(n));
}
