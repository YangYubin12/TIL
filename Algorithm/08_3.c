#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct DNode{
   element data;
   struct DNode* prev;
   struct DNode* next;
}DNode;

void init(DNode* phead){ //헤드노드 초기화
   phead->prev = phead;
   phead->next = phead;
}
void dinsert(DNode* before,element data){ //before 다음노드로 삽입      
   DNode* newnode = (DNode*)malloc(sizeof(DNode));
   newnode->data = data; //데이터 저장
   newnode->prev = before; //이전노드 주소값 저장
   newnode->next = before->next; //이전노드의 next값 저장
   before->next ->prev = newnode; //이전노드의 넥스트 노드의 prev값을 새로운 노드 주소값으로 저장 시험
   before->next = newnode; //이전노드의 next값을 새로운 노드 주소값으로 저장;
   
}
void ddelete(DNode* head, DNode* removed){
   if(removed == head) return;
   removed->prev->next = removed->next; //삭제할 노드의 next값으로 저장;
   removed->next->prev  = removed->prev; //삭제노드의 prev값으로 저장;
   free(removed);
}
void printDlist(DNode* phead){
   DNode* p;
   for(p=phead->next;p!=phead;p=p->next){
      //초기값:head->next, head위치가 아니면 출력
      printf("<-| |%d| |->",p->data);
   }
   printf("\n");
}
int main() {
   DNode* head = (DNode*)malloc(sizeof(DNode)); //헤드노드 동적할당    
   init(head); //헤드노드 초기화
   printf("추가단계\n");
   for(int i = 0;i< 5;i++){
      dinsert(head,i);
      printDlist(head);
   }
   printf("삭제단계\n");
   for(int i = 0;i<5;i++){
      printDlist(head);
      ddelete(head,head->next);
   }
   free(head);
   return 0;
}
