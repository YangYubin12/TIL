#include <stdio.h>
int main() {
   int num1[10],num2=0,j=0;
   for(int i=0;i<9;i++){
      scanf("%d",&num1[i]);
   }
   for(int i=0;i<9;i++){
      if(num1[i]>num2){
         num2 = num1[i];
         j=i;
      }
   }
   printf("%d\n",num2);
   printf("%d\n",j+1);
   return 0;
}
