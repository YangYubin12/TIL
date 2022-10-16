#include <stdio.h>
int arr[100][100] = {0, };
int main()
{
    int n, m, count = 1;
    scanf("%d %d", &n, &m);
    for (int num = 0; num < n + m - 1; num++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + j == num)
                {
                    arr[j][i] = count++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
