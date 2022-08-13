//지그재그
//#include <stdio.h>
//int main(void)
//{
//    int Arr[101][101] = {};
//    int n;
//    scanf_s("%d", &n);
//    int x = 1;
//    for (int i = 1; i <= n; i++) {
//        if (i % 2 == 1) {
//            for (int j = 1; j <= n; j++) {
//                Arr[i][j] = x;
//                x++;
//            }
//        }
//        else {
//            for (int j = n; j >= 1; j--) {
//                Arr[i][j] = x;
//                x++;
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            printf("%d ", Arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

#include <stdio.h>
int main() 
{
    int input;
    scanf("%d", &input);

    for (int i = 0; i < input; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j <= input; j++) {
                printf("%d ", (i * input) + j);
            }
        }
        else
            for (int j = input; j > 0; j--) {
                printf("%d ", (i * input) + j);
            }
        printf("\n");
    }
    return 0;
}
