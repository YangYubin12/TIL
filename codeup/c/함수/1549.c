#include <stdio.h>
long long int n;

long long int abs(long long int i)
{
    if (n >= 0)
    {
        return i;
    }
    else
    {
        return -i;
    }
}

int main()
{
  scanf("%lld", &n);
  printf("%lld\n", abs(n));
  return 0;
}
