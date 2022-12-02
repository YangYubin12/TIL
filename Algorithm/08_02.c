#include <stdio.h>
#include <stdlib.h>
typedef char element; 
typedef struct QNode{ //큐 노드 구조체정의
    element data; //데이터변수
    struct QNode* next; //링크변수
} QNode;

typedef struct QList{ //연결리스트큐 구조체정의
    QNode *front,*rear; //front, rear 포인터변수 정의
} QList;

QList *createQList(){
   QList *q;
   q = (QList *)malloc(sizeof(QList));
   q->front = NULL; //초기값 설정
   q->rear = NULL; //초기값 설정
   return q;
}

int isEmpty(QList *q) 
{ 
   if (q->front == NULL) { //시험
      printf("\n Linked Queue is empty! \n");
      return 1;    
   }
    else return 0; 
} 

void enQueue(QList *q, element item) 
{ 
    QNode* newNode=  (QNode*)malloc(sizeof(QNode)); //동적할당
    newNode->data = item;
    newNode->next = NULL;
    if(q->front == NULL) { //비어있는 리스트이면
       q->front = newNode;
       q->rear = newNode;
    }
    else {
      q->rear->next = newNode;
      q->rear = newNode;
    }
}

element deQueue(QList *q) 
{ 
   QNode *removed = q->front; //삭제할 대상 노드주소 저장
   element item;
   if (isEmpty(q)) return 0; 
    else {
       item =  removed->data;
       q->front = q->front->next;
       if(q->front == NULL){ 
            q->rear = NULL;
       }
       free(removed);
       return item;
    }
} 

element peek(QList *q){ 
    element item;
    if (isEmpty(q)) return 0; 
    else {
       item = q->front->data;
       return item;
    }
}

void printList(QList *q)
{
   QNode *p = q->front; //리스트의 처음 노드 주소 저장
   printf("\n[");
   while(p!=NULL) { //p에 저장된 노드주소가 NULL이 아니면
      printf(" %c", p->data);
      p =  p->next; //다음 노드로 주소 이동
   }
   printf(" ]");
}

int main(void) 
{ 
   QList *q = createQList(); 
   element data; 
   enQueue(q, 'A');    printList(q);
   enQueue(q, 'B');     printList(q);
   deQueue(q);      printList(q);
   enQueue(q, 'C');   printList(q);
   data = peek(q);   printf("\n peek item : %c", data);
   deQueue(q);      printList(q);
   deQueue(q);      printList(q);
   return 0; 
}
