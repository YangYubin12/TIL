#include <stdio.h>
int f_sum(int n)
{
    int value = n;
    int sum = 0;
    while (1){
        if (value == 0) { break; }
        sum += (value % 10);
        value /= 10;
    }
    return sum;
}
 
int main() 
{
    int i,sum;
    scanf("%d", &i);
    while (1){
        if (i < 10) { break; }
        i = f_sum(i);
    }
    printf("%d",i);
 
    return 0;
}
