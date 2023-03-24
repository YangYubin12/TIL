#include <stdio.h>
int n;
void f(int n)
{
    int i=0;
    for(int j=1;j<=n;j++)
        n%j==0 ? i++:0;
    i==2? printf("prime"):printf("composite");
    return 0;
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}
