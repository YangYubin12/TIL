#include <stdio.h>

void myswap(int *i, int *j)
{
    if (*i > *j)
    {
        int temp = *j;
        *j = *i;
        *i = temp;
    }
}

main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    myswap(&a, &b);
    printf("%d %d", a, b);
}
