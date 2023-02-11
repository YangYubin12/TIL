# include<stdio.h>
int main()
{
	int num[100][100];
	int sum = 0;
	int n, i, j, m, k, l;
	scanf("%d %d", &n, &m);
	for(i = 0; i<n; i++)  
	{
		for(j = 0; j<m; j++)
		{
			scanf("%d ",&num[i][j]);
			sum = 0;
			for(k = 0; k<=i; k++)
			{
				for(l = 0; l<=j; l++)
				{
					sum += num[k][l];
				}
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
	return 0;
}
