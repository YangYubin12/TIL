#include <stdio.h>
int n;
void f(int x)
{
    printf(x==1 ? "hello\n": x==2 ? "world\n": "\n");
    return 0;
}
int main()
{
  scanf("%d", &n);
  f(n);
  return 0;
}
