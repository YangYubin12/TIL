#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int n,m;
    scanf("%d %d", &n, &m);
    int x = n*m;
    int i = 1;
    int j = 1; 
    int X = 1;
    int Y = 1;
    for(int k = 1; k <= n*m; k++){
        Arr[i][j] = x;
        x--;
        if( j <=m && X == 1 && Y == 1){
            if(j+1 <= m && Arr[i][j+1] == 0){j++;}
            else{
                i++;
                X = -1;
            }
        }
        else if( i <=n && X == -1 && Y == 1){
            if(i+1 <= n  && Arr[i+1][j] == 0){i++;}
            else{
                j--;
                Y = -1;
            }
        }
        else if(  j >=1 && X == -1 && Y == -1){
            if(j-1 > 0 && Arr[i][j-1] == 0){j--;}
            else{
                i--;
                X = 1;
            }
        }
        else if(i >=1 && Y == -1 && X == 1 ){
            if(i-1 >0 & Arr[i-1][j] == 0){
                i--;}
            else{
                j++;
                Y = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
