#include<stdio.h>
int arr[10000001] = {1,2,4};
int main(void)
{
    int n, i;
    scanf("%d", &n);
    for(i=3;i<=n;i++){
        arr[i] = (arr[i-1] + i)%137;
    }
    printf("%d", arr[n]);
    return 0;
}
