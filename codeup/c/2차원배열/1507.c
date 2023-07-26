#include<stdio.h>
int main()
{
	int arr[100][100] = {0,};
	int i, j, k, x1, x2, y1, y2;
	int sum = 0;
	for(i = 0; i<4; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(j = x1; j<x2; j++)
		{
			for(k = y1; k<y2; k++)
			{
				arr[j][k] = 1;
			}
		}
	}
	for(i = 0; i<100; i++)
	{
		for(j = 0; j<100; j++)
		{
			if(arr[i][j] == 1)
			{
				sum ++;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
