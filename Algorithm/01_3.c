//배열의 이름은 주소 상수!
#include <stdio.h>
void outputArray(int arr[], int s);
int inputArray(int arr[]);
int main()
{
   int a[100];
   int i, j, size;
   size = inputArray(a);
   outputArray(a, size);
   return 0;   
}
int inputArray(int a[]){
   int i, num;
   for(i=0; i<=99; i++)
   {
      scanf("%d", &num);
      if(num==0)
      {
         break;
      }
      else{
         a[i] = num;
      }
   }
   return i-1;
}
void outputArray(int a[], int s){
   for(int  j = s; j>=0; j--)
   {
         printf("%d ",a[j]);
   }
}
