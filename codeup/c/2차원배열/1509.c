#include<stdio.h>
int main()
{
	int arr[12][11] = {0,};
	int i, j;
	for(i = 1; i<=11; i++)
	{
		for(j = 1; j<=10; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for(i = 1; i<=10; i++)
	{
		if(arr[11][i]!=0)
		{
			int num = 0;
			for(j = 1; j<=10; j++)
			{
				if(arr[j][i] > 0)
				{
					num = 1;
				}
				else if(arr[j][i] < 0)
				{
					num = -1;
				}
			}
			if(num == 1)
			{
				printf("%d crash\n", i);
			}
			else if(num == -1)
			{
				printf("%d fall\n", i);
			}
			else
			{
				printf("%d safe\n", i);
			}
		}
	}
	return 0;
}
