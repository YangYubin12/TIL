#include <stdio.h>
int N,M;
int arr[10000001] = {};
int num;
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &num);
        arr[num] = 1;
    }
    
    scanf("%d", &M);
    for (int i = 0; i < M; i++){
        scanf("%d", &num);
        printf("%d ", arr[num]);
    }
    
    return 0;
}
