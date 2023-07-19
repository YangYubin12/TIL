#include<stdio.h>
int main()
{
	int arr[51][51] = {0,};
	int i, j, n, num=1;
	scanf("%d",&n);
	for(i = 1; i<=n; i++)
	{
		if(i %2 == 0)
			for(j = n; j>=1; j--)
				arr[i][j] = num++;
		else
			for(j = 1; j<=n; j++)
				arr[i][j] = num++;
	}
	for(i = 1; i<=n; i++)
	{
		for(j = 1; j<=n; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}
