//시험 문제!
#include <stdio.h>
#include <stdlib.h>
typedef struct DNode{
	int index; //풍선 터지는 순서
	int data; //풍선의 데이터
	struct DNode* prev;
	struct DNode* next;
}DNode;
typedef struct Head{
	int size; //해당 리스트의 크기(풍선의 개수)
	DNode* link; //연결리스트 시작주소
}Head;
//이중연결 노드 구조체 정의
//이중연결리스트 Head 구조체 정의

void insertLast(Head* head, int data);
void deleteNode(Head* head);
int main(){
	Head* phead = (Head*)malloc(sizeof(phead)); //연결 리스트의 헤더 생성
	phead->link = NULL;
	phead->size = 0;
	//원형 이중 연결 리스트 사이즈(풍선개수)를 입력
	int size,num;
	scanf("%d", &size); //5
	//숫자를 입력받아 리스트에 풍선노드 추가
	for (int i = 0; i < size; i++){
		scanf("%d", &num); //3 2 1 -3 -1 
		insertLast(phead, num); //리스트에 노드에 삽입 함수 호출
	}
 for (int i = 0; i < size; i++){
		deleteNode(phead); //리스트 노드 삭제
	}
	free(phead->link);
	free(phead);
  return 0;
}

void insertLast(Head* phead, int data)
{
	//리스트에 새로 추가될 노드
	DNode* head = phead->link;
	DNode* newNode = (DNode*)malloc(sizeof(DNode)); //동적할당
	newNode->data = data;
	newNode->index = phead->size + 1; //리스트 크기 +1

	//리스트 마지막 위치에 노드 삽입
	if (head == NULL){ //리스트에 최초삽입시 초기화
		phead->link = newNode;
		newNode->prev = newNode;
		newNode->next = newNode;
	}
	else{	
		newNode->prev = head->prev; //(1)
		newNode->next = head;//(2)head
		head->prev->next = newNode; //(3)
		head->prev = newNode;
		}
	//리스트 사이즈를 증가시켜 인덱스로 활용
	phead->size++;
}

void deleteNode(Head* phead){
	DNode* head = phead->link;
	int index = head->index; //풍선의 번호
	int count = head->data; //풍선 안에 들어 있는 숫자의 값
	printf("%d ", index);
	//풍선이 하나 남아 있을 때 종료
	if (phead->size == 1){
		phead->size--;
		return;
	}
	//삭제할 풍선을 가리키는 노드
	DNode* removed = head; //삭제할 노드 주소 저장
	DNode* p = head;//순회할 시작 주소 저장
	if (count > 0){ //양수일때
		for (int i = 0; i < count; i++){
			p = p->next; //다음노드 방향으로 이동
			if (p == removed){ //터트릴 풍선 skip
				p = p->next;
			}
		}
	}
	else
	{
		for (int i = 0; i < count * (-1); i++){
			p = p->prev;//음수일때 이전 노드 방향 이동
		 //탐색 한 위치가 삭제할 노드이면 skip
			if (p == removed){
				p = p->prev;
			}
		}
	}
	phead->link = p;//마지막 순회한 위치를 새로운 head 주소로 저장
	removed->prev->next = removed->next; //삭제할 다음노드와 연결
	removed->next->prev = removed->prev; //삭제할 이전노드와 연결  
  free(removed);
	phead->size--;
}
void printList(Head* phead){
	DNode* p = phead->link;
	do{
		printf("[%d] ->",p->data);
		p = p->next;	
	}while(p!=phead->link);
}
