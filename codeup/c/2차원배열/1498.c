#include<stdio.h>
#include<limits.h>
int main()
{
	int arr[1000] = {0,};
	int i, j, n, a;
	int min = INT_MAX;
	scanf("%d %d", &n, &a);
	for(i = 0; i<n; i++)
		scanf("%d ", &arr[i]);
	for(i = 0 ; i<n; i+=a)
	{
		min = arr[i];
		for(j = i; j<i+a; j++)
		{
			if(j < n)
			{
				if(min > arr[j])
				{
					min = arr[j];
				}
			}
		}
		printf("%d ", min);
	}
	return 0;
}
