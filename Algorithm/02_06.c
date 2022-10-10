//문자열별삼각형(재귀) 방법1
//  #include<stdio.h>
//   char star[20];
//   void f(int n) { //재귀함수 종료조건 1. return
//    if(n==0) return; //2. } 만났을 때
// 		f(n-1); //2라인
// 		for(int i=1; i<=n; i++){
// 			printf("*");
// 		}
// 		printf("\n");
// 	} 

//  int main() {
//     int n;
//     scanf("%d", &n); //5
//     f(n); //f(5)
//  }

//방법2
#include<stdio.h>
  char star[20];
  void f(int n) {
     if(n==0) return; //재귀함수 종료조건 1. return
      f(n-1);
      star[n]='*';
      printf("%s\n", star+1);
   } 

 	int main() {
    int n;
    scanf("%d", &n); //5
    f(n); //f(5)
 }
