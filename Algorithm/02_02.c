//안 배열, 조건에 맞게
#include <stdio.h>
#include <stdlib.h>
int maxh(int* h, int n) {
	int i ;
	int max = *(h+0);
	//for문을 이용하여 최대값 검색
	for(i=1; i<n; i++){
		if(*(h+i) > max) max = *(h+i);
	}
	return max;
}
int main(){
  int n, i ;
  int* h;
	scanf("%d", &n) ; //5가 들어왔다고 가정
	h = (int*)malloc(sizeof(int)*n); //메모리 동적할당 
	// n개의 데이터 입력 저장
	for(i=0; i<n; i++){
		scanf("%d", h+i);
	}
	printf("%d\n", maxh(h, n)) ;
	
	free(h);
  return 0; 
}
