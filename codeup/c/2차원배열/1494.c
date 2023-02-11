# include<stdio.h>
int main()
{
	int d[101]={0,};
	int n, m, i, j, u, s, e, k;
	int sum =0;
	scanf("%d %d", &n, &k);
	for(i = 1; i<=k; i++)
	{
		scanf("%d %d %d", &s, &e, &u);
		d[s] = d[s]+u;
		d[e+1] = d[e+1]-u;
	}
	for(i = 1; i<=n; i++)
	{
		printf("%d ", d[i]);
	}
	printf("\n");
	for(i = 1; i<=n; i++)
	{
		sum += d[i];
		printf("%d ", sum);
	}
	return 0;
}
