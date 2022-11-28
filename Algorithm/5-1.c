#include <stdio.h>
#define MAX 100
typedef char element;
typedef struct Stack{
	element str[MAX];
	int top;
}Stack;

void initStack(Stack *s){ //초기화코드
	s->top = -1;
}

int isFull(Stack *s){
	return s->top == MAX-1;
}

int empty(Stack *s){
	return s->top == -1;
}

void push(Stack* s, char c){
	if(isFull(s)){
		printf("FULL");
 }
	else{
		s->top++;
		s->str[s->top]=c;
	}
}

char pop(Stack *s){
	char Temp;
	if(empty(s)){
		printf("EMPTY");
		return 0;
	}
	Temp = s->str[s->top];
	s->top--;
	return Temp;
}

int palindrome(char str[]){
	Stack S;
	int i=0;
	initStack(&S);
	while(str[i]!='\0'){
		push(&S,str[i]);
		i++;
	}
	i=0; 
	while(str[i]!='\0'){
		if(pop(&S) != str[i])return 0;
		i++;
	}
	return 1;
}

int main(void){
	char str[MAX];
	scanf("%s",str);
	if(palindrome(str))
	printf("TRUE");
	else
	printf("FALSE");
	return 0;
}
