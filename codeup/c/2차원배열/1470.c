#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n;
    scanf("%d", &n);
    int x = 1;
    for(int i = 1; i <= n; i++){
        if(i%2 == 1){
            for(int j = 1; j<=n; j++){
                Arr[j][i] = x;
                x++;
            }
        }
        else{
            for(int j = n; j>=1; j--){
                Arr[j][i] = x;
                x++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n ; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
