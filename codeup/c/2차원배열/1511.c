#include<stdio.h>
int main() 
{
	int a;
	scanf("%d", &a);
	int n = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 1; j <= a; j++) {
			if (i == 0 || i == a - 1 || j == 1 || j == a)
				n += i * a + j;
		}
	}
	printf("%d", n);
	return 0;
}
