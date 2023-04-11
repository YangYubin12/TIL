#include <stdio.h>
int n;
void f(int n)
{
    printf(n==0 ? "false": "true");
    return 0;
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}
