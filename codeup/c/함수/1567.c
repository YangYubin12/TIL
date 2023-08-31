#include <stdio.h>

int n, a, b, d[1010];
long long int subsetsum(int a, int b)
{
    long long int i, s = 0;

    for (i = a; i <= b; i++)
        s += d[i];

    return s;
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d%d", &a, &b);

  printf("%lld\n", subsetsum(a, b));
}
