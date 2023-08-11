#include <stdio.h>
int n;
long long int d[110];

long long int f(void)
{
    long long int i, m = d[1];
    for (i = 2; i <= n; i++)
    {
        if (m > d[i])
        {
            m = d[i];
        }
    }
    return m;
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%lld", &d[i]);

  printf("%lld", f());
  return 0;
}
