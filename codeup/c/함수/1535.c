#include <stdio.h>

int n, d[110];


int f(void)
{
    int i, index = 0, m = d[0];
    for (i = 1; i < n; i++)
    {
        if (m < d[i])
        {
            m = d[i];
            index = i;
        }
    }
    return index + 1;
}
int main()
{
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%d", &d[i]);

  printf("%d", f());
  return 0;
}
