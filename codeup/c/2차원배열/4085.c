#include<stdio.h>
int main()
{
    int map[101][101] = {};
    int m, n, x, y;
    scanf("%d %d %d %d", &m, &n, &x, &y);
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<= m; j++)
            scanf("%d ", &map[i][j]);
    int sum = 0;
    int a = 0;
    for(int i = 1; i<=n-y+1; i++){
        for(int j = 1; j<= m-x+1; j++){
            for(int k = 0; k<y; k++){
                for(int l = 0; l<x; l++){
                    sum += map[i+k][j+l];
                }
            }
            if(sum > a)
                a = sum;
            sum = 0;
        }
    }
    printf("%d", a);
    return 0;
}
