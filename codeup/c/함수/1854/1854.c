// 1854: 재귀로 각 자리 수의 합 리턴
// 금지 키워드: while, goto, for
// long long int형 정수(n) 1개가 입력
// ex) 입력: 1234 -> 출력: 10
#include <stdio.h>
#include <string.h>
char str[30];
int n;
int f(int k) {
	if (k == n) return 0;
	return f(k + 1) + str[k] - '0';
}
int main() {
	scanf("%s", str);
	n = strlen(str);
	printf("%d", f(0));
	return 0;
}