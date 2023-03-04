#include<stdio.h>
int memo[201]={0};
long long int recur(int a){
	if(a==1||a==2){
		memo[a] = 1;
		return 1;
	}
	if(memo[a]!=0){
		return memo[a];	
	}
	else{
		return memo[a] = (recur(a-1) + recur(a-2))%10009;
	}
}

int main(){
	int a;
	scanf("%d", &a);
	long long int result = recur(a);
	printf("%lld\n", result);
	
	return 0;
}
