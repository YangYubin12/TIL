#include <stdio.h>
int n;
int prime(int k)
{
    int i;
    for(i=2;i<k;i++)
        if(k%i==0)
            break;
    return i==k;
}
int main()
{
  scanf("%d", &n);
  if(prime(n)) printf("prime");
  else printf("composite");
  return 0;
}
