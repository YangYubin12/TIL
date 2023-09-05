#include <stdio.h>

int n, k, d[1010];
int lower_bound(k)
{
	for (int i = 1; i <= n; i++)
		if (d[i] >= k)
			return i;
	return n + 1;
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d", &k);

  printf("%d\n", lower_bound(k));
}
