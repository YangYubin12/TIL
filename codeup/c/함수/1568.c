#include <stdio.h>

int n, a, b, d[1010];

int maxi(int a, int b)
{
    int m = d[a];
    for (int i = a; i <= b; i++)
        if (m < d[i])
            m = d[i];
    for (int i = a; i <= b; i++)
        if (m == d[i])
            return i;
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d%d", &a, &b);

  printf("%d\n", maxi(a, b));
}
