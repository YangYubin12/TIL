#include <stdio.h>

int n, m;

long long int f(int i, int j)
{
    return (long long int)i + j;
}

int main()
{
  scanf("%d%d", &n, &m);
  printf("%lld\n", f(n, m));
}
