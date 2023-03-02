#include<stdio.h>
int f(a, b){
    if(b>a){
        return 0;
    }
    else if(a==b||b==0){
        return 1;
    }
    else{
        return f(a-1, b-1) + f(a-1, b);
    }
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", f(a, b));
}
