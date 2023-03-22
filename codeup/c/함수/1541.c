#include <stdio.h>
int n;
void f(int n)
{
    printf(n<0 ? "negative": n==0 ? "zero":"positive");
    return 0;
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}
