#include <stdio.h>

int n;

long long int f(int n)
{
    if (n == 1)
        return 1;
    else
        return n * f(n - 1);
}

int main()
{
  scanf("%d", &n);
  printf("%lld\n", f(n));
}
