#include <stdio.h>
#include <stdlib.h>
void genRandom(int a[][5], int r);
void outputArray(int a[][5], int r);
float averageScore(int *row, int size);
int main() {
   int score[4][5], i ;
   genRandom(score, 4);
   outputArray(score, 4);	
   for(i = 0 ; i < 4 ; i ++){
      printf("선수 %d : %.2f\n", i+1, averageScore(score[i], 5));
   }	
   return 0;
}

void genRandom(int a[][5], int r){
   int i, j;
   for(i = 0 ; i < r ; i ++)
      for(j = 0 ; j < 5 ; j ++)
         a[i][j] = (rand() % 10) + 1;  // 이 부분에 rand 함수를 이용해 1~10 정수 생성
}

void outputArray(int a[][5], int r){
   int i, j;
   for(i=0;i<r;i++) {
      for(j=0;j<5;j++) {
         printf("%d ", a[i][j]);
      }
      printf("\n");
   }
   // a배열의 r행 5열의 데이터 출력
}

float averageScore(int *row, int size){
   // 선수 한명의 점수를 입력 받아 절사 평균을 구하여 출력
   int max=0,min=1000,i,tot=0;
   for(i=0;i<size;i++) {
      if(max < row[i]) {
         max = row[i];
      }
      if(min > row[i]) {
         min = row[i];
      }
   }
   for(i=0;i<size;i++) {
      tot += row[i];
   }
   tot -= max;
   tot -= min;
   return tot/3.0;
}
