#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
typedef char element;
typedef struct{
	int top;
	element data[STACK_SIZE];
}Stack;//스택 구조체 정의
int checkTest(char expr[]);
void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, element data);
element pop(Stack *s);
int main(){
	int i;
	Stack s;
	char expr[20];
	printf("괄호포함 수식 입력 : ");
	scanf("%s", expr);
	if (checkTest(expr)) printf("성공");
	else printf("실패");
	return 0;
}
void initStack(Stack *s){
	s->top =-1;//초기화코드
}
int isFull(Stack *s){
	return s->top == STACK_SIZE-1;//코드작성
}
int isEmpty(Stack *s){
	return s->top == -1;//코드작성
}
void push(Stack *s, element c){
	if(isFull(s)){
		printf("stack is full\n");
		return ;
	}
	s->top++;
	s->data[s->top]=c;//push 코드작성
}
element pop(Stack *s){
	if(isEmpty(s)/*스택이 비었으면*/){
		printf("stack is empty\n");
		return 0 ;
	}
	return s->data[s->top--];
	//pop 코드작성
}
int checkTest(char expr[]){
	int i;
	Stack s;
	initStack(&s);
	char ch,open_ch;
  for(i=0;expr[i]!='\0';i++){
		ch = expr[i];//코드작성
		switch(ch){
			case '(': 
			case '[':
			case '{':
			push(&s, ch);//코드작성
				break;
			case ')':
			case ']':
			case '}':	
				if (isEmpty(&s)) return 0;
				open_ch = pop(&s);//코드작성
				if ((open_ch == '(' && ch != ')') ||
					  (open_ch == '[' && ch != ']') ||
					  (open_ch == '{' && ch != '}') ) {
					return 0;
				}
				//printf("open_ch=%c\n",open_ch);
				break;
		}
	}
	if (!isEmpty(&s)) return 0;
	return 1;
}
