#include <stdio.h>

double abs(double i)
{
	if (i * -1 > 0)
		return -i;
	else
		return i;
}

int main()
{
	double i;
	scanf("%lf", &i);
	printf("%.10g", abs(i));
	return 0;
}
