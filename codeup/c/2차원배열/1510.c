#include<stdio.h>
int main()
{
	int n;
	int arr[50][50];
	scanf("%d", &n);
	int x = (int)(n / 2);
	int y = 0;
	for (int s = 1; s <= n * n; s++){
		arr[y--][x++] = s;
		if (s % n == 0) {
			y+=2;
			x--;
			continue;
		}
		if (x > n-1) {
			x = 0;
		}
		if (y < 0) {
			y = n -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}
