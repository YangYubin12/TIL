#include <stdio.h>
int n;
void f(int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("*");
    return 0;
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}
