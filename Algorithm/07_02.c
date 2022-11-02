#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	char data[4];
	struct Node *next;
}Node;

//공백 연결 리스트를 생성
Node *createList(){
	Node* head = (Node *)malloc(sizeof(Node));
	head = NULL;
	return head;
}

Node* deleteAll(Node* head){
	Node *p = head;
	Node* removed; 
	if (p == NULL) return NULL;
	while(p != NULL){
		//free할 주소를 removed 저장   
		removed = p;
		p = p->next;//다음 주소로 이동;
		//removed 주소 할당해제
		free(removed);
		removed = removed->next = NULL;//할당해제 후 NULL참조로 저장
	}
	return head;   
}
// 연결 리스트를 순서대로 출력하는 연산
void printList(Node *head){
	Node *p = head;//
	printf("L =(");
	while(p != NULL){
	//p의 값을 출력 처음에는 head 의 값
		printf("%s", p->data); 
		//p 를 다음 값으로 이동
		p = p->next;
		//다음데이터가 있으면 ->출력
		if(p) printf("->");
   }
	printf(") \n");
}

//첫번째 노드로 삽입하는 연산
Node*  insertFirst(Node *head, char* x){
	Node* newNode = (Node *)malloc(sizeof(Node));//동적할당
	// 새 노드의 데이터 필드에 x 저장
	strcpy(newNode->data, x);
	// newNode와 head 를 연결하기
	newNode->next = head;
	//newNode를 새로운 head로 저장하기
	head = newNode;
	return head;
}

//노드를 pre 뒤에 삽입하는 연산
Node* insertMiddle(Node* head, Node* pre, char* x){
	Node* newNode = (Node *)malloc(sizeof(Node)); //동적할당
	strcpy(newNode->data, x); //데이터 저장
	if(head == NULL || pre == NULL){ //오류
		newNode->next = NULL;
		head = newNode;
	}
	else {
	//뉴노드를 pre 뒤에 값으로 연결하고
	newNode->next = pre->next;
	//프리뒤를 newnode로 설정
	pre->next = newNode;
	}
	return head; //헤드주소 리턴;
}
Node* insertLast( Node *head, char *x){
	Node* newNode = (Node *)malloc(sizeof(Node)); //새노드 동적할당;
	Node* temp;  
	strcpy(newNode->data, x);
	//newNode 는 마지막이니까 null값
	newNode->next = NULL;
	if(head==NULL) //head가 null이면
	{
	//newNode가 head주소로 저장 
		head = newNode;
		return head;
	}
	temp = head;
	while(temp -> next != NULL) 
		temp = temp -> next;
		temp->next = newNode;
	return head;
}

Node *searchNode(Node *head, char *x){
	Node *temp =head;
	while (temp != NULL){
		if(strcmp(temp->data, x) == 0) return temp;
		else temp = temp->next;
	}
	return temp;
}

int main(){
	Node* head;
	Node * p;
	printf("(1) 공백리스트 생성하기! \n");
	head = createList();
	printList( head );   
	printf("(2) 리스트 처음에 [수]노드 삽입하기! \n");
	head =insertFirst( head, "수");
	printList( head ); 
	printf("(3) 리스트 마지막에 [금]노드 삽입하기! \n");
	head =insertLast( head, "금");
	printList( head );   
	printf("(4) 리스트 첫 번째에 [월]노드 삽입하기! \n");
	head =insertFirst( head, "월");
	printList( head);   
	printf("(5) 리스트에서 [수] 노드를 찾아 그 뒤에 [목] 삽입하기! \n");
	p = searchNode(head, "수");
	if( p == NULL ) printf("찾는 데이터가 없습니다.\n");
	else    head = insertMiddle( head, p, "목");
	printList( head );  
	printf("(6) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
	deleteAll(head);
	printList( head );
	return 0;
}
