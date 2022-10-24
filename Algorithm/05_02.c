#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
typedef int element;
typedef struct{
	int top;
	element data[STACK_SIZE];
}Stack;//Stack 구조체 구현
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, element data);
int pop(Stack *s);
void initStack(Stack* s);

int main(){
	int menu;
	element data ;
	Stack s;
	initStack(&s);
	do{
		printf("1:push, 2:pop, 0:exit : ");
		scanf("%d", &menu);
		switch( menu ){
			case 1 :
				printf("데이터 입력 : ");
				scanf("%d", &data);
				//스택에 입력
				push(&s, data);
				break;
			case 2 :
        data = pop(&s);//스택에서 출력
        if(data)
				  printf("pop 데이터 : %d\n", data);
				break;
      case 0 :
        break;
			default :
				printf("잘못된 입력 입니다. \n");
				break;
		}
	}while( menu );
}
void initStack(Stack *s){ //top 포인터를 -1로 초기화
	s->top = -1;
}
int isFull(Stack *s){ //스택이 가득 차 있으면 true 리턴
	return s->top == STACK_SIZE-1;
}
int isEmpty(Stack *s){ // 스택이 비어 있으면 true 리턴
	return s->top == -1;	
}
void push(Stack *s, element data){ //스택이 가득 차 있으면 문구 출력 후 리턴, 아니면 push
	if(isFull(s)){
		printf("Stack is Full\n");
		exit(0);
	}
	s->top++;
	s->data[s->top] = data;
}
element pop(Stack *s){ //스택이 비어  있으면 문구 출력 후 0 리턴, 아니면 맨 위 데이터 리턴
	if(isEmpty(s)){
		printf("Stack is Empty\n");
		exit(0);
	}
	return s->data[s->top--];
}
