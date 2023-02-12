#include<stdio.h>
int main()
{
	int d[1001][1001]={};
	int i, j, n, m, k, sum=0;
	int x1,x2,y1,y2,u;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 1; i<=k; i++)
	{
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &u);
		d[x1][y1] = d[x1][y1]+u;
		d[x2+1][y2+1] = d[x2+1][y2+1]+u;
		d[x1][y2+1] = d[x1][y2+1]-u;
		d[x2+1][y1] = d[x2+1][y1]-u;
	}	
	for(i = 0; i<n; i++)
	{
		for(j = 0; j<m; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i<n; i++)
	{
		for(j = 0; j<m; j++)
		{
			sum += d[i][j];
			d[i][j] = sum;
		}
		sum = 0;
	}
	sum = 0;
	for(i = 0; i<m; i++)
	{
		for(j = 0; j<n; j++)
		{
			sum +=d[j][i];
			d[j][i] = sum;
		}
		sum = 0;
	}
	for(i = 0; i<n; i++)
	{
		for(j = 0; j<m; j++)
		{
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	return 0;
}
