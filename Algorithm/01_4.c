#include <stdio.h>
void inputArray( int a[], int size);
void outputArray( int a[], int size);
int insertArray( int a[], int num, int index, int size);
int deleteArray( int a[], int index, int size);

int main(){
  int a[10], size=0 ;
  size = insertArray( a, 10, 0, size);
  size = insertArray( a, 20, 1, size);
  size = insertArray( a, 30, 2, size);
  size = insertArray( a, 50, 2, size);
	outputArray(a,size);
	size = deleteArray(a, 1, size);
  outputArray(a, size);
  return 0;
}
void inputArray( int a[], int size){
    int i;
    for(int i=0; i<size; i++){
			scanf("%d", &a[i]);
		}
}
void outputArray( int a[], int size){
    int i;
     //배열 크기 만큼 데이터 출력
	for(int i=0; i<size; i++){
		printf("%d ", a[i]);
	}
    printf("\n");
}
int insertArray( int a[], int num, int index, int size){
    if(index == size){
			a[index]=num;
			size++;//여기에 배열 끝부분에 원소 삽입코드 작성 
		 } 
	  else{    // 여기에 배열 중간에 원소 삽입 코드
			for(int i =size; i>=index+1; i--){
				a[i]=a[i-1];
			}
			a[index]=num;
			size++;
		}
  return size;
}
int deleteArray( int a[], int index, int size){
  if(index == size-1){
		a[index]=0;
		size--;
	}
	else{ //여기에 배열 중간의 원소 삭제 코드
		size--;
		for(int i=index; i<=size-1; i++){
			a[i]=a[i+1];
		}
	}
  return size;
}
