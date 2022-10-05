#include <stdio.h>
#include <string.h>
int main() {
   char str[100];
   int num, i, len;
   scanf("%s", &str);
   for(i=0; str[i]!='\0'; i++){
      if(str[i] == ','){
         printf("%d\n",num);
         num=0;
         continue;
      }
      num=num*10+(str[i]-'0');
   }
   printf("%d\n", num);
   return 0;
}
