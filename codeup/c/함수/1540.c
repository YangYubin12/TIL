#include <stdio.h>
int n;
void f(int n)
{
    printf(n==0 ? "zero": "non zero");
    return 0;
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}
