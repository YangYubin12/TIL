#include<stdio.h>
int main()
{
	int arr[1000] = {0,};
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d ", &arr[i]);
	for(i = 0 ; i<n; i+=2)
	{
		if(arr[i] > arr[i+1])
			printf("%d ", arr[i]);
		else
			printf("%d ", arr[i+1]);
	}
	return 0;
}
