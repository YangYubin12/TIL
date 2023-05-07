#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n,m;
    scanf("%d %d", &n , &m);
    int x = 1;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=m; j++){
            Arr[i][j] = x;
            x++;
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = m; j >=1 ; j--){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
