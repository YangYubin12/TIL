//5개 문자형 원소를 입력 받아 역순으로 출력
//순서대로 출력한 다음 수정하여 작성
//배열 이름은 주소 상수
#include <stdio.h>
char a[5];
int inputArray(char a[]){
	char i;
	for(i=0; i<5; i++){
		scanf("%c", &a[i]);
		getchar();
	}
	return i;
}
void outArray(char a[]){
	int temp =* (a+1);
	for(int i=4; i>=0; i--)
		printf("%c", a[i]);
}
int main(){
	char a[5];
	int i, size = 0;
	size = inputArray(a); //배열 a의 주소
	outArray(a);
  return 0;
}
