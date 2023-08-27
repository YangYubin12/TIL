#include <stdio.h>

int n, m, x;

int max(int p, int q){ return p>=q?p:q;}

int min(int p, int q){ return p<q?p:q;}

int mid(int n, int m, int x)
{
    int i, j;
    i = max(n, m);
    i = max(x, i);
    j = min(n, m);
    j = min(x, j);
    return (n + m + x) - (i + j);
}

int main()
{
  scanf("%d%d%d", &n, &m, &x);
  printf("%d\n", mid(n, m, x));
}
