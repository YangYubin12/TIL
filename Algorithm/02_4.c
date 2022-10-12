#include <stdio.h>
#include <string.h>
int main() {
   char s[1000001];
   int count[27] = {0, };
   int max = 0;
   scanf("%s", &s);
   int cnt = 0;
   int num;
   
   for(int i = 0; i <= strlen(s); i++) {
      if(s[i] >= 'A' && s[i] <= 'Z') count[s[i] - 'A']++; 
      else if(s[i] >= 'a' && s[i] <= 'z') count[s[i] - 'a']++;
   }
   
   for(int i = 0; i < 26; i++) {
      if(count[i] > max) {
         max = count[i];
         num = i;
      }
   }
   
   for(int i = 0; i < 26; i++) {
      if(count[i] == max) cnt++;
   }
   
   if(cnt == 1) printf("%C", num + 'A');
   else printf("?");
   
   return 0;
}
