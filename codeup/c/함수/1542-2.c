#include <stdio.h>
int n;
void f(int n)
{
    int i,j=0;
    for(i=2;i*i<=n;i++)
        n%i ? j:j++;
    printf(j? "composite":"prime");
    return 0;
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}
