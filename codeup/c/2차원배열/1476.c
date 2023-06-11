#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n,m;
    scanf("%d %d", &n, &m);
    int x = 1;
    int j = 1;
    for(int i = 1; i <=n+m; i++){
        int a = i;
        if(a > n){
            a = n;
            j++;
        }
        int b = j;
        while(a > 0){
            if(i + 1 ==  a + b){
                Arr[a][b] = x;
                x++;
            }
                a--;
                b++;
            if(b > m){break;}
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
