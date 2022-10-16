#include <stdio.h>
int arr[101][101] = {1};
int i, j, x, y, n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int safe(int a, int b) {
   return (a >= 0 && a < n) && (b >= 0 && b < n);
}
int main() {
   int nx, ny, cnt = 1;
   scanf("%d", &n);
   int c = n * n;
   while (c > cnt) {
      ny = y + dy[i % 4], nx = x + dx[i % 4];
      if (safe(ny, nx) && !arr[ny][nx]) {
         arr[ny][nx] = ++cnt;
         y = ny, x = nx;
      }
      else i++;
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }	
   return 0;
}
