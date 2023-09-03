#include <stdio.h>

int n, k, d[1010];
int findi(int k)
{
    int i, j = -1;

    for (i = 1; i <= n; i++)
    {
        if (k == d[i])
        {
            j = i;
            break;
        }
    }

    return j;
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d", &k);

  printf("%d\n", findi(k));
}
