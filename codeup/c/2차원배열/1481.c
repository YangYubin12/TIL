#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n,m;
    scanf("%d %d", &n, &m);
    int x = 1;
    int i = n;
    int j = m; 
    int a = i;
    int b = j;
    for(int k = 1; k <=n*m; k++){
        if( ( i >= 1 && i <= n) && ( j >= 1 && j <= m) ){
            Arr[i][j] = x;
            x++;
            i--;
            j++;
            if( !(( i >= 1 && i <= n) && ( j >= 1 && j <= m)) ){ 
                b--; 
                if(b <=0){ 
                    b = 1;
                    a--;
                }
                i = a;
                j = b;
            }
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
