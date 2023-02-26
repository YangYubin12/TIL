#include <stdio.h>
int a[172][172], b[172][172], i, j;
int n, m, k, bir, l, d;
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &bir, &l, &d);
    for(i = 1; i <= n; i++)
        for(j = 1 ;j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            b[i][j] = 0;
        }
    scanf("%d", &k);
 
    while(k--)
    {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
            {
                b[i][j] = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + a[i][j-1] + a[i][j+1] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1];
                if(a[i][j] == 0)
                    b[i][j] = b[i][j] == bir ? 1 : 0;
                else
                    b[i][j] = (l <= b[i][j] && b[i][j] < d) ? 1 : 0;
            }
 
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                a[i][j] = b[i][j];          
    }
 
    for(i = 1; i <= n; i++, puts(""))
        for(j = 1; j <= m; j++)
            printf("%d ", b[i][j]);
    return 0;
}
