#include <stdio.h>
int main()
{
    int mine[12][12] = {};
    int x,y;
    for(int i = 1; i <= 9; i ++)
        for(int j = 1; j <= 9; j ++)
            scanf("%d ",&mine[i][j]);
    scanf("%d %d",&x,&y);
    if(mine[x][y] == 1)
        printf("-1");
    else
        printf("%d",mine[x-1][y-1] + mine[x-1][y] + mine[x-1][y+1] + mine[x][y-1] + mine[x][y+1] + mine[x+1][y-1] + mine[x+1][y] + mine[x+1][y+1]);
    return 0;
}
