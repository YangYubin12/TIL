#include <stdio.h>
#include <string.h>
int main()
{
   int len, i;
   int c[255]={0};
   char str[91];
   gets(str);
   for(i = 0; str[i] !='\0'; i++)
   {
      c[str[i]]++;
   }
   for(i = 'A'; i <= 'Z'; i++)
   {
      if(c[i]>0)
      printf("%c : %d\n",i, c[i]);
   }
	 return 0;
}
