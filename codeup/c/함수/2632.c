# include <stdio.h>
int m;

int print(int n)
{
   if(n <= 2)
      return n;
   else
      return print(n-2) + print(n-1);
}

int main()
{
   scanf("%d",&m);
   printf("%lld",print(m));
   
   return 0;
}
