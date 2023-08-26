#include <stdio.h>

int n, m;
int max(int i, int j)
{
    return i >= j ? i : j;
}

int main()
{
  scanf("%d%d", &n, &m);
  printf("%d\n", max(n, m));
}
