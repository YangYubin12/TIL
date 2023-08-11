#include <stdio.h>
int n;

char grade(int n)
{
    if (n >= 90)
    {
        return 'A';
    }
    else if (n >= 80)
    {
        return 'B';
    }
    else if (n >= 70)
    {
        return 'C';
    }
    else if (n >= 60)
    {
        return 'D';
    }
    return 'F';
}

int main()
{
  scanf("%d", &n);
  printf("%c", grade(n));
  return 0;
}
