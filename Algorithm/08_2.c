#include <stdio.h> 
#include <stdlib.h>
typedef int element;
//노드 구조체 작성
typedef struct Node{
   element data;
   struct Node* next;
}Node;

void printList(Node* head){
   Node *p = head->next; //리스트의 첫위치 저장
   int count = 0;
   if (head == NULL) return;
   do {
      if(p == NULL) break;
      printf("%d->",p->data);
      p = p->next; //다음 노드값 저장
 }while(p != head->next); //p의 값이 첫위치가 아니면 //시험!! 한개만 남아서 자기 자신을 가리킬때
 //}while(cnt <10);
   printf("\n");
}
/*void insertFirst(Node* head, element data){
   Node* node = (Node*)malloc(sizeof(Node));//새노드 동적할당
   node->data = //
   if (head == NULL){//리스트에 노드가 없는경우
      head =  node//새로운 노드주소값
      head->next = head;//자신을 순환참조
   }
   else{
      node->next = head->next;//원래 리스트의 첫위치값
      head->next = node;//새로운 노드 주소값     
   }
   return head;
}*/
Node* insertLast(Node* head, element data){
   Node* node = (Node*)malloc(sizeof(Node)); //새노드 동적할당
   node->data =data;
   if (head == NULL){
      head = node; //새로운 노드주소값
      head->next = head; //자신을 순환참조
   }
   else{
      node->next = head->next;
      head->next = node; //새노드 주소
      head = node; //새로운 head 주소 리턴
   }
   return head;
}

Node* chageCard(Node* head){
   Node* removed = head->next; //노드삭제위치 저장,head->next인 이유는 문제봐라
   head->next = removed->next; //(head->next)->next 똑같다 시험!!!!!!!!! 삭제된 다음 위치와 연결
   free(removed);
   return head->next; //새로운 헤드값으로 리턴 문제봐라
}
int main() {
   Node *head =NULL, *p;
   int n;
   printf("카드개수 입력\n");
   scanf("%d",&n);
	 //printf("마지막위치에 연결\n");
   for(int i = 1;i <= n;i++){
      head = insertLast(head,i); //노드 삽입함수 호출
   }
	 //printf("head노드 = %d\n",head->data);
   while(head->next != head){ //1개만 남아 자기 자신을 가르킬떄
      head = chageCard(head); //카드 제거함수 호출
      printList(head);
   }
   printf("마지막 카드번호 : %d",head->data);
   return 0;
}
