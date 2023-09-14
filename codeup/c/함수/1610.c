#include <stdio.h>

int main()
{
	int s, cnt;
	char str[100];

	scanf("%s", str);
	scanf("%d %d", &s, &cnt);

	for (int i = s; i < s + cnt; i++)
		printf("%c", str[i]);

	return 0;
}
