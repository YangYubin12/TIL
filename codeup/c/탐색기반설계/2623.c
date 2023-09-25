#include <stdio.h>
int gcd(int i, int j)
{
    int mod = i % j;
    while (mod > 0)
    {
        i = j;
        j = mod;
        mod = i % j;
    }
    return j;
}

int main()
{
    int i, j;
    scanf("%d %d", &i, &j);
    printf("%d", gcd(i, j));
    return 0;
}
