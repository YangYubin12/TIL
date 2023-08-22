#include <stdio.h>

int n;

int f(int n)
{
    int i, j = 0;

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            j++;
        }
    }

    return j;
}

int main()
{
  scanf("%d", &n);
  printf("%d\n", f(n));
}
