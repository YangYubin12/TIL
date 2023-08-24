#include <stdio.h>

long long int n, m;
long long int f (long long int n, long long int m)
{
    if (n >= m)
        return n - m;
    else
        return m - n;
}

int main()
{
  scanf("%lld%lld", &n, &m);
  printf("%lld\n", f(n, m));
}
