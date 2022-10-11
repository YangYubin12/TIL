#include <stdio.h>
#include <string.h>
int ispalandrom(char* mystr1) {
   int len = 0, i;
   int flag = 1;
   len = strlen(mystr1); //입력문자열의 길이 저장
   
   for(i=0 ;i < len / 2; i++) {
      if (*(mystr1 + i) != *(mystr1 + len - 1 - i)) { //예를 들어 level 에서 v를 기준으로 양옆 문자를 비교하여 다르다면
         flag = 0;   
      }
   }   
   return flag ;
}

int main() {
   char mystr1[256];
   char mystr2[256]; 

   gets(mystr1); 
   if (ispalandrom(mystr1)) { //펠린드롬 판정 함수 호출
      printf("Yes\n");
   }
   else {
      printf("No\n");
   } 
   return 0;
}
