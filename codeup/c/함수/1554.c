#include <stdio.h>

double x;

long long int f(double x)
{
    long long int i = (long long int)x;
    if (x < i)
        return x - 1;
    else
        return x;
}

int main()
{
  scanf("%lf", &x);
  printf("%lld\n", f(x));
}
