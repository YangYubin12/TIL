#include <stdio.h>

double x;

double f(double i)
{
    return i - (long long int)i;
}

int main()
{
  scanf("%lf", &x);
  printf("%.14lf\n", f(x));
}
