#include <stdio.h>

long long int n;

int sqrt(long long int n)
{
    long long int j;
    for (j = 0; j * j < n; j++);
    if (j * j == n)
    {
        return j;
    }
    else
    {
        return j - 1;
    }
}

int main()
{
  scanf("%lld", &n);
  printf("%d\n", sqrt(n));
  return 0;
}
