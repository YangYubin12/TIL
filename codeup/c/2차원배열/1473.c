#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n, m;
    scanf("%d %d", &n, &m);
    int x = 1;
    int k = 1;
    for(int i = n; i >= 1; i--){
        if(k%2 == 1){
            for(int j = 1; j<=m; j++){
                Arr[i][j] = x;
                x++;
            }
        }
        else{
            for(int j = m; j>=1; j--){
                Arr[i][j] = x;
                x++;
            }
        }
        k++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
