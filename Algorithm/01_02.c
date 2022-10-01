#include <stdio.h>
int main() {
   int num1,num2=0,num3[101];
   scanf("%d",&num1);
   for(int i =0;i<num1;i++){
      scanf("%d",&num3[i]);
   }
   for(int i=0;i<num1;i++){
      printf("%d:",i+1);
      for(int j=0;j<num1;j++){
         if(i==j){
            
         }else if(num3[i] > num3[j]){
            printf(" >");
         }
         else if(num3[i] < num3[j]){
            printf(" <");
         }
         else{
            printf(" =");
         }
      }
      printf("\n");
   }
   return 0;
}
