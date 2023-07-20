#include<stdio.h>
int main()
{
	int arr[101][101] = {0,};
	int i, j, n, num=1;
	scanf("%d",&n);
	for(i = 1; i<=n; i++)
	{
		if(i %2 == 0)
			for(j = n; j>=1; j--)
				arr[j][i] = num++;
		else
			for(j = 1; j<=n; j++)
				arr[j][i] = num++;
	}
	for(i = 1; i<=n; i++)
	{
		for(j = 1; j<=n; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}
