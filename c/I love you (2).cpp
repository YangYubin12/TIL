//문자열_love -> I love you 헤헤
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char cArr[100];
    gets_s(cArr);  
    if (cArr[0] == 'l') {
        if (cArr[1] == 'o') {
            if (cArr[2] == 'v') {
                if (cArr[3] == 'e') {
                    if (cArr[4] == '\0') {
                        printf("I love you.");
                    }
                }
            }
        }
    }
    return 0;
}
