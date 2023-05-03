#include<stdio.h>
int main(void)
{
    int Arr[101][101] = {};
    int num;
    scanf("%d", &num);
    int x = 1;
    for(int i = 1; i <=num; i++){
        for(int j = 1; j<= num; j++){
            Arr[i][j] = x;
            x++;
        }
    }
    for(int i = 1; i <=num; i++){
        for(int j = 1; j<= num; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
