#include <stdio.h>
void inputArray(int a[][3], int r);
void outputArray(int a[][3], int r);
void addMatrix(int a[][3], int b[][3], int r);
void subMatrix(int a[][3], int b[][3], int r);
void scalarMul(int a[][3], int r, int n);
int main() {
   int A[2][3], B[2][3];
   int row=2, col=3;
   int num ;
   printf("2*3 행렬의 각 원소의 값을 입력하시오.\n");
   inputArray(A, row);
   inputArray(B, row);
   printf("행렬 A, B\n");
   outputArray(A, row);
   outputArray(B, row);
   
   printf("행렬합 \n");
   addMatrix(A, B, row );
   printf("행렬차 \n");
   subMatrix(A, B, row );
   
   printf("곱할 정수 입력\n");
   scanf("%d", &num);
   scalarMul(A, row, num);
   
   return 0;
}

void inputArray(int a[][3], int r){
    int i, j;
    //r행 3열을 입력받는 코드를 작성
      for(i=0;i<r;i++) {
         for(j=0;j<3;j++) {
            scanf("%d", &a[i][j]);
         }
      }
}

void outputArray(int a[][3], int r){
    int i, j;
    for(i=0;i<r;i++) {
         for(j=0;j<3;j++) {
            printf("%d ", a[i][j]);
         }
         printf("\n");
      }
}

void addMatrix(int a[][3], int b[][3], int r){
   for(int i=0;i<r;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ", a[i][j] + b[i][j]);
      }
      printf("\n");
   } 
}

void subMatrix(int a[][3], int b[][3], int r){
   for(int i=0;i<r;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ", a[i][j] - b[i][j]);
      }
      printf("\n");
   }
}

void scalarMul(int a[][3], int r, int n){
   for(int i=0;i<r;i++) {
      for(int j=0;j<3;j++) {
         printf("%d ", a[i][j] * n);
      }
      printf("\n");
   }
}
