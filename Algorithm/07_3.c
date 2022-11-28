#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ArrayList{
   element array[100];
   int size;
}ArrayList;

int main() {
   ArrayList* L;
   //L->size=0;
   L = (ArrayList*)malloc(sizeof(ArrayList));
   L->array[0] = 10;
   L->size++;
   for(int i=0;i<L->size;i++){
      printf("%d->",L->array[i]);
   }
   printf("\n");
   
   L->array[1] = 20;
   L->size++;
   for(int i=0;i<L->size;i++){
      printf("%d->",L->array[i]);
   }
   printf("\n");
   L->array[2] = 30;
   L->size++;
   for(int i=0;i<L->size;i++){
      printf("%d->",L->array[i]);
   }
   printf("\n");
   
   L->array[3] = 40;
   L->size++;
   for(int i=0;i<L->size;i++){
      printf("%d->",L->array[i]);
   }
   printf("\n");
   
   L->array[4] = L->array[3];
   L->array[3] = L->array[2];
   L->array[2] = 100;
   L->size++;
   for(int i=0;i<L->size;i++){
      printf("%d->",L->array[i]);
   }
   printf("\n");
   
   L->array[1] = L->array[2];
   L->array[2] = L->array[3];
   L->array[3] = L->array[4];
   L->size--;
   for(int i=0;i<L->size;i++){
      printf("%d->",L->array[i]);
   }
   return 0;
}
