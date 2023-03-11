#include <stdio.h>

char f(void)
{
    return 'A';
}
int main()
{
    printf("%c", f() );
    return 0;
}
