# include<stdio.h>
# include<limits.h>
int main()
{
	int arr[1000] = {0,};
	int i, j, n, a;
	int max = INT_MIN;
	scanf("%d %d", &n, &a);
	for(i = 0; i<n; i++)
		scanf("%d ", &arr[i]);
	for(i = 0 ; i<n; i+=a)
	{
		max = arr[i];
		for(j = i; j<i+a; j++)
		{
			if(j < n)
			{
				if(max < arr[j])
				{
					max = arr[j];
				}
			}
		}
		printf("%d ", max);
	}
	return 0;
}
