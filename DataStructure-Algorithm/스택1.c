#include <stdio.h>
#include <stdbool.h>
#define STACK_SZ	3   // 옆 글자를 발견하면 3으로 바꿔인식 해라 

//#define TRUE	1    -----> <stdbool.h>에 포함 !!
//#define FALSE	2

// 공백 체크  
int isEmpty();    
// 포화 체크  
int isFull();

// 스택에 입력 
void push(int); 
// 스택에서 출력 
int pop(); 
// 맨위의 스택 확인 
int peek(); 

// 출력 
void printStack(); 

int stack[STACK_SZ]; 
int top = -1; // 현재 스택의 위치 초기화, 한개씩 들어올때 마다 +1 


int main(void)
{
	push(10); 
	push(11); 
	push(12); 
	push(13); 

	pop(); 
	
	printStack(); 


	return 0; 
}

int isEmpty()
{
	if (top <= -1) return true;
	else return false; 
}
int isFull()
{
	if (top >= STACK_SZ - 1) return true;
	else return false; 
}
void push(int data)
{
	if (isFull()) {
		printf("STACK overflow!!\n"); 
		return; 
	}
	else {
		stack[++top] = data; 
	}
}
int pop()
{
	if (isEmpty()) {
		printf("STACK underflow!!\n");
		return; 
	}
	else {
		return stack[top];
		top--; 
		// == stack[top--];
	}
}
int peek()
{
	if (isEmpty()) {
		printf("STACK underflow!!\n"); 
		return; // == exit(1); 
	}
	else {
		return stack[top]; 
	}
}
void printStack()
{
	int i; 
	if (!isEmpty()) {
		for ( i = 0; i <= top; i++){
			printf("%d    ", stack[i]); 
		}
		printf("\n"); 
	}
}
