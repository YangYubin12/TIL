#include <stdio.h>
int n;

#include<stdbool.h>
bool zero (int k)
{
    return !k;
}

int main()
{
  scanf("%d", &n);
  if(zero(n)) printf("zero");
  else printf("non zero");
  return 0;
}
