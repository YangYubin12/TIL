# include<stdio.h>
int main()
{
	int num[100];
	int sum=0;
	int n, i, j, m;
	scanf("%d",&n);
	for(i = 0; i<n; i++)
	{
		scanf("%d",&num[i]);
		sum += num[i];
		printf("%d ",sum);
	}
	return 0;
}
