#include <stdio.h>
int main() {
  char* str;
  int a, b;
  str = (char*)malloc(sizeof(char)*100);
  scanf("%s", str);
  scanf("%d %d", &a, &b);
  *(str+b)='\0';
  printf("%s",str+a-1);
}
