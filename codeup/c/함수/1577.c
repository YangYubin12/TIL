#include <stdio.h>
int myabs(int a){
    if(a <= 0)
        a *= -1;
    return a;
}
main()
{
    int a;
    scanf("%d", &a);
    printf("%d", myabs(a));
}
