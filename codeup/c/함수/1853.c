#include <stdio.h>

int n;

int f(int k)
{
  if(k <= 1) return 1;
  return f(k-1)+k;
}

int main()
{
  scanf("%d", &n);
  printf("%d\n", f(n));
}
