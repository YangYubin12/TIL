#include <stdio.h>
int memo[100001]={1, 1, 2};

int recur(int a){
	if(a==1) return 1;
	if(memo[a]!=0) return memo[a];
	else return memo[a] = (recur(a-1) + recur(a-2) + recur(a-3))%1000;
}

int main(){
	int a;
	scanf("%d", &a);
	printf("%d\n", recur(a));
	return 0;
}
