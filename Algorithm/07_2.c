// 함수를 활용해 node 동적으로 생성하기
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Node {
  element data;
  struct Node* next; //자기참조 구조체: 자기자신을 참조하는 포인터를 포함
}Node;
Node *createNode(element data);
void printAll(Node *ptr);
int main(){
  Node *head, *node1,*node2, *node3;
	node1 = createNode(12); //node1, node2, node3 노드 생성
	node2 = createNode(99);
	node3 = createNode(37); //각 노드->next를 저장
	//printf("%p %p %p", node1, node2, node3);
	node1->next=node2;
	node2->next=node3;
	head = node1;
	printAll(head); //head 노드를 출력
}
Node *createNode(element data){
	Node *newNode = (Node*)malloc(sizeof(Node)); //노드 크기 동적 할당
	newNode->data = data; //노드의 데이터 저장
	newNode->next = NULL; //노드->next 참조를 NULL저장
	return newNode;
}
void printAll(Node* ptr){
	while(ptr!=NULL){
		if (ptr->next){ //next 노드가 있으면 ->출력
			printf("%d->", ptr->data); //노드의 데이터 출력 
			ptr = ptr->next; //다음노드의 주소로 저장
		}
		else {
			printf("%d\n", ptr->data); //노드의 데이터 출력
			return; //프린트 종료
		}
	}
}
