#include<stdio.h>
int main()
{
    int i, j, k, a, b, c, d, x, y;
    int n[101][101] = { 0 };
    scanf("%d %d", &x, &y);
    scanf("%d", &k);
    for (i = 1; i <= k; i++) 
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (j = 0; j < a; j++)
            if (b == 0)
                n[c][d + j] = 1;
            else if (b == 1)
                n[c + j][d] = 1;
    }
    for (i = 1; i <= x; i++) 
    {
        for (j = 1; j <= y; j++)
        printf("%d ", n[i][j]);
        printf("\n");
    }
    return 0;
}
