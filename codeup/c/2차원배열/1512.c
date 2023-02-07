#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n, x, y;
    scanf("%d\n%d %d", &n, &x, &y);
    Arr[x][y] = 1;
    int v = Arr[x][y];
    for(int i = x-1; i >= 1; i-- ){
        Arr[i][y] = ++v;
    }
    v = Arr[x][y];
    for(int i = x+1; i <= n; i++ ){
        Arr[i][y] = ++v;
    }
    for(int i = 1; i <= n; i++){
        v = Arr[i][y];
        for(int j = y-1; j >= 1; j-- ){
            Arr[i][j] = ++v;
        }
        v = Arr[i][y];
        for(int j = y+1; j <= n; j++ ){
            Arr[i][j] = ++v;
        }
    }
    for(int i  = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
