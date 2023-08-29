#include <stdio.h>

int a, b;

int gcd(int a, int b)
{
    int i = a % b;

    while (i > 0)
    {
        a = b;
        b = i;
        i = a % b;
    }

    return b;
}

int main()
{
  scanf("%d%d", &a, &b);
  printf("%d\n", gcd(a, b));
}
