#include<stdio.h>
int main()
{
    int map[22][22] = {};
    int p[9][2] = {};
    int n;
    for(int i = 1; i <= 10; i ++)
        for(int j = 1; j <= 10; j ++)
            scanf("%d ",&map[i][j]);
    for(int i = 1; i <= 10; i ++){
        for(int j = 1; j <= 10; j ++){
            if(map[i][j] > 0){ 
                int ballon = map[i][j];
                int up = 0;
                int down = 0;
                int right = 0;
                int left = 0;
                for(int k = 1; k<= ballon; k++){
                    map[i][j] = -2;
                    if(map[i+k][j] != -1 && down == 0 && map[i+k][j]<=0){
                        map[i+k][j] = -2;
                    }
                    else if(map[i+k][j] == -1){
                        down = 1;
                    }
                    if(map[i-k][j] != -1 && up == 0 && map[i-k][j]<=0 ){
                        map[i-k][j] = -2;
                    }
                    else if(map[i-k][j] == -1){
                        up = 1;
                    }
                    if(map[i][j+k] != -1 && right == 0 && map[i][j+k]<=0){
                        map[i][j+k] = -2;
                    }
                    else if(map[i][j+k] == -1){
                        right = 1;
                    }
                    if(map[i][j-k] != -1 && left == 0 && map[i][j-k]<=0){
                        map[i][j-k] = -2;
                    }
                    else if(map[i][j-k] == -1){
                        left = 1;
                    }
                }
            }
        }
    }
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d",&p[i][0],&p[i][1]);
        if(map[p[i][0]][p[i][1]] == 0)
            map[p[i][0]][p[i][1]] = i;
    }
    for(int i = 1; i <= 10; i ++){
        for(int j = 1; j <= 10; j ++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
    printf("Character Information\n");
    for(int i = 1; i <= n; i++){
        int x,y;
        x = p[i][0];
        y = p[i][1];
        if(map[x][y] == i)
            printf("player %d survive\n",i);
        else
            printf("player %d dead\n",i);
    }
    return 0;
}
