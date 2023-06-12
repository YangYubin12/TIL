#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n,m;
    scanf("%d %d", &n, &m);
    int x = 1;
    int i = 1;
    for(int j = 1; j <=n+m; j++){
        int b = j;
        if(b > m){
            b = m;
            i++;
        }
        int a = i;
        if(a + b > n+m){
            break;
        }
        while(b > 0){
            if(j + 1 ==  a + b){
                Arr[a][b] = x;
                x++;
            }
                a++;
                b--;
            if(a > n){break;}
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
