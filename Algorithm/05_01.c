#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 100
typedef int element; //int를 element로 재정의
typedef struct{
	int top;
	element data [STACK_SIZE];
}Stack;

Stack s; //전역변수로 스택 구조체 선언선언

void initStack(){
	s.top=-1;
}
int isEmpty(){
 	if(s.top == -1) return 1;
	return 0;
}
int isFull(){
	if(s.top == STACK_SIZE-1) return 1;
	return 0;
}	 
void push(element item){
	if(isFull()){
		printf("Stack if Full\n");
		return;
	}
	s.top++;
	s.data[s.top] = item;
}
element pop(){ //반환 후 제거
	element temp;
	if(isEmpty()){
		printf("Stack if Empty\n");
		return;
	}
	temp = s.data[s.top];
	s.top--;
	return temp;
}
element peek(){ //반환만
	if(isEmpty()){
		printf("Stack if Empty\n");
		exit(1);
	}
	return s.data[s.top];
}
int main(){
	initStack();
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",peek());
	printf("%d\n",pop());
	return 0;
}
